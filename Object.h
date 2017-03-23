#pragma once

#include "Vec.h"
#include "Color.h"
#include "Ray.h"

class Object
{
public:

	virtual Color getColor() { return Color(0.0, 0.0, 0.0, 0); }

	//	Will be overloaded by the object subclasses and so is marked virtual
	virtual double findIntersection(Ray ray) {
		return 0;
	}

	virtual Vec getNormalAt(Vec point) {
		return Vec(0, 0, 0);
	}

	Object();

	~Object();
};