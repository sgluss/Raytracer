#pragma once

#include "math.h"

class Vec
{
private:
	double x, y, z;

public:

	double getX() { return x; }
	double getY() { return x; }
	double getZ() { return x; }

	double magnitude() {
		return sqrt(x*x + y*y + z*z);
	}

	Vec normalize () {
		double mag = this->magnitude();
		return Vec(x / mag, y / mag, z / mag);
	}

	Vec negative() {
		return Vec(-x, -y, -z);
	}

	double dotProduct(Vec v) {
		return x*v.getX() + y*v.getY() + z*v.getZ();
	}

	Vec crossProduct(Vec v) {
		return Vec(
			y*v.getZ() - z*v.getY(),
			z*v.getX() - x*v.getZ(),
			x*v.getY() - y*v.getX());
	}

	Vec vecAdd(Vec v) {
		return Vec(x+v.getX(), y+v.getY(), z+v.getZ());
	}

	Vec vecMult(double scalar) {
		return Vec(x * scalar, y * scalar, z * scalar);
	}

	Vec();
	
	Vec(double, double, double);

	~Vec();
};

