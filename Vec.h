#pragma once

#include "math.h"

class Vec
{
private:
	double _x, _y, _z;

public:

	double getX() { return _x; }
	double getY() { return _y; }
	double getZ() { return _z; }

	double magnitude() {
		return sqrt(_x*_x + _y*_y + _z*_z);
	}

	Vec normalize () {
		double mag = this->magnitude();
		if (mag < 0.000001) {
			return Vec(0, 0, 0);
		}
		return Vec(_x / mag, _y / mag, _z / mag);
	}

	Vec negative() {
		return Vec(-_x, -_y, -_z);
	}

	double dotProduct(Vec v) {
		return _x*v.getX() + _y*v.getY() + _z*v.getZ();
	}

	Vec crossProduct(Vec v) {
		return Vec(
			_y*v.getZ() - _z*v.getY(),
			_z*v.getX() - _x*v.getZ(),
			_x*v.getY() - _y*v.getX());
	}

	Vec vecAdd(Vec v) {
		return Vec(_x+v.getX(), _y+v.getY(), _z+v.getZ());
	}

	Vec vecMult(double scalar) {
		return Vec(_x * scalar, _y * scalar, _z * scalar);
	}

	Vec();
	
	Vec(double, double, double);

	~Vec();
};

