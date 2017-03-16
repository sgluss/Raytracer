#pragma once

#include "Vec.h"
#include "Color.h"
#include "Ray.h"

class Object
{
public:

	Color getColor() { return Color(0.0, 0.0, 0.0, 0); }

	double findIntersection(Ray ray) {
		return 0;
	}

	Object();

	~Object();
};