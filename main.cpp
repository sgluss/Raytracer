#pragma warning(disable:4996)

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <cmath>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//	Raytrace specific classes
#include "Vec.h"
#include "Ray.h"
#include "Cam.h"
#include "Color.h"
#include "Light.h"

#include "Object.h"
#include "Sphere.h"
#include "Plane.h"

using namespace std;

struct RGB {
	double r;
	double g;
	double b;
};


void setBMPHeaders(int w, int h, int s, int ppm, int fileSize, unsigned char* bmpFileHeader, unsigned char* bmpInfoHeader) {
	bmpFileHeader[2] = (unsigned char)(fileSize);
	bmpFileHeader[3] = (unsigned char)(fileSize >> 8);
	bmpFileHeader[4] = (unsigned char)(fileSize >> 16);
	bmpFileHeader[5] = (unsigned char)(fileSize >> 24);

	bmpInfoHeader[4] = (unsigned char)(w);
	bmpInfoHeader[5] = (unsigned char)(w >> 8);
	bmpInfoHeader[6] = (unsigned char)(w >> 16);
	bmpInfoHeader[7] = (unsigned char)(w >> 24);

	bmpInfoHeader[8] = (unsigned char)(h);
	bmpInfoHeader[9] = (unsigned char)(h >> 8);
	bmpInfoHeader[10] = (unsigned char)(h >> 16);
	bmpInfoHeader[11] = (unsigned char)(h >> 24);

	bmpInfoHeader[21] = (unsigned char)(s);
	bmpInfoHeader[22] = (unsigned char)(s >> 8);
	bmpInfoHeader[23] = (unsigned char)(s >> 16);
	bmpInfoHeader[24] = (unsigned char)(s >> 24);

	bmpInfoHeader[25] = (unsigned char)(ppm);
	bmpInfoHeader[26] = (unsigned char)(ppm >> 8);
	bmpInfoHeader[27] = (unsigned char)(ppm >> 16);
	bmpInfoHeader[28] = (unsigned char)(ppm >> 24);

	bmpInfoHeader[29] = (unsigned char)(ppm);
	bmpInfoHeader[30] = (unsigned char)(ppm >> 8);
	bmpInfoHeader[31] = (unsigned char)(ppm >> 16);
	bmpInfoHeader[32] = (unsigned char)(ppm >> 24);
}

void saveImage(const char *fileName, int w, int h, int dpi, RGB *data) {
	FILE *file;
	int pixelCount = w * h;
	int s = 4 * pixelCount;

	// 54 bytes for BMP header info
	int fileSize = 54 + s;

	double factor = 39.375;
	int m = static_cast<int>(factor);

	int ppm = dpi * m;

	unsigned char bmpFileHeader[14] = {'B', 'M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
	unsigned char bmpInfoHeader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

	setBMPHeaders(w, h, s, ppm, fileSize, bmpFileHeader, bmpInfoHeader);

	file = fopen(fileName, "wb");

	fwrite(bmpFileHeader, 1, 14, file);
	fwrite(bmpInfoHeader, 1, 40, file);

	for (int i = 0; i < pixelCount; i++) {
		RGB rgb = data[i];

		double red = (data[i].r) * 255;
		double green = (data[i].g) * 255;
		double blue = (data[i].b) * 255;

		unsigned char color[3] = { (int)floor(blue), (int)floor(green), (int)floor(red) };

		fwrite(color, 1, 3, file);
	}

	fclose(file);
}

int getNearestObject(vector<double> intersections) {
	if (intersections.size() == 0) {
		return -1;
	}
	else if (intersections.size() == 1) {
		if (intersections.at(0) > 0) {
			return 0;
		}
		else {
			//	The ray missed
			return -1;
		}
	}
	else {
		//	There is  more than 1 intersection
		double min = DBL_MAX;
		//	return -1 if all intersections are negative
		int minIndex = -1;
		int curVal;

		for (int i = 0; i < intersections.size(); i++) {
			curVal = intersections.at(i);
			if (curVal > 0 && curVal < min) {
				min = curVal;
				minIndex = i;
			}
		}
		return minIndex;
	}
}

int main() {
	cout << "rendering..." << endl;

	int index;

	int dpi = 72;
	int width = 800;
	int height = 600;
	
	int n = width * height;

	double aspectRatio = (double)width / (double)height;

	RGB *pixels = new RGB[n];

	Vec origin(0, 0, 0);
	Vec vecX(1, 0, 0);
	Vec vecY(0, 1, 0);
	Vec vecZ(0, 0, 1);

	//	Build inputs for Scene camera
	Vec camPos(2, 1, -2);
	Vec camTarget(0, 0, 0);
	Vec difference(camPos.getX() - camTarget.getX(),
					camPos.getY() - camTarget.getY(),
					camPos.getZ() - camTarget.getZ());

	Vec camDir = difference.negative().normalize();
	Vec camRight = vecY.crossProduct(camDir).normalize();
	Vec camDown = camRight.crossProduct(camDir);

	Cam sceneCam(camPos, camDir, camRight, camDown);

	//	Establish colors
	Color whiteLight(1, 1, 1, 0);
	Color green(0.5, 1.0, 0.5, 0.3);
	Color deepPurple(0.66, 0.33, 0.66, 0.15);
	Color grey(0.5, 0.5, 0.5, 0);
	Color black(0, 0, 0, 0);

	//	Set Scene light
	Vec LightPos(-8, 10, -10);
	Light sceneLight(LightPos, whiteLight);

	//	Scene objects
	Sphere sphere1(origin, 1, green);
	Plane plane1(vecY, -1, deepPurple);

	vector<Object*> sceneObjects;
	sceneObjects.push_back(dynamic_cast<Object*>(&sphere1));
	sceneObjects.push_back(dynamic_cast<Object*>(&plane1));

	//	offsets for camera direction when not using AntiAliasing
	//	used to create image plane for camera
	double xOffset, yOffset;

	//	Cam Ray preallocation. 
	//	Ray will travel from camera, through specific x,y pixel in image plane into the scene
	//	to look for intersections with objects
	Vec camRayOrigin = sceneCam.getCamPosition();
	Vec camRayDirection;
	Ray camRay(camRayOrigin, camRayDirection);

	vector<double> intersections;
	int indexOfNearestObject;

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			index = y * width + x;

			//	start with no AntiAliasing, set offsets for different x/y ratios
			if (width > height) {
				xOffset = ((x + 0.5) / width) * aspectRatio - ((width - height) / (double)height) / 2;
				yOffset = ((height - y) + 0.5) / height;
			}
			else if (height > width)
			{
				xOffset = (x + 0.5) / width;
				yOffset = (((height - y) + 0.5) / height) / aspectRatio - (((height - width) / (double)width) / 2);
			}
			else
			{
				xOffset = (x + 0.5) / width;
				yOffset = ((height - y) + 0.5) / height;
			}

			camRayDirection = camDir.vecAdd(camRight.vecMult(xOffset - 0.5).vecAdd(camDown.vecMult(yOffset - 0.5))).normalize();

			for (int i = 0; i < sceneObjects.size(); i++)
			{
				intersections.push_back(sceneObjects.at(i)->findIntersection(camRay));
			}

			indexOfNearestObject = getNearestObject(intersections);

			if (x > width / 4 && x < (width * 3 / 4) &&
				y > height / 4 && y < (height * 3 / 4)) {
				pixels[index].r = 80;
				pixels[index].g = 40;
				pixels[index].b = 20;
			}
			else {
				pixels[index].r = 80;
				pixels[index].g = 0;
				pixels[index].b = 0;
			}

			intersections.clear();
		}
	}

	saveImage("test.bmp", width, height, dpi, pixels);

	return 0;
}