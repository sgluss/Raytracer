#pragma once

#include "math.h"
#include "Vec.h"
#include "Color.h"

#include "Object.h"

class Plane : public Object
{
private:
	Vec _normal;
	double _distance;
	Color _color;

public:

	Vec getNormal() { return _normal; }
	double getDistance() { return _distance; }
	Color getColor() { return _color; }

	Vec getNormalAt(Vec point) {
		return _normal;
	}

	//	returns distance from ray origin to point of intersection
	double findIntersection(Ray ray) {
		Vec rayDirection = ray.getDirection();
		double a = rayDirection.dotProduct(_normal);

		if (a == 0) {
			//	ray is parallel to plane
			return -1;
		}
		double b = _normal.dotProduct(ray.getOrigin().vecAdd(_normal.vecMult(_distance).negative()));
		return -1 * (b / a);
	}

	Plane();

	Plane(Vec, double, Color);

	~Plane();
};