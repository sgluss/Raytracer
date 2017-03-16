#pragma once

#include "math.h"
#include "Vec.h"
#include "Color.h"

#include "Object.h"

class Sphere : public Object
{
private:
	Vec _center;
	double _radius;
	Color _color;

public:

	Vec getCenter() { return _center; }
	double getRadius() { return _radius; }
	Color getColor() { return _color; }

	Vec getNormalAt(Vec point) {
		//	Normal points away from the center of the sphere
		Vec normalVec = point.vecAdd(_center.negative().normalize());
		return normalVec;
	}

	double findIntersection(Ray ray);

	Sphere();

	Sphere(Vec, double, Color);

	~Sphere();
};