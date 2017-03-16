#pragma once

#include "Vec.h"

class Ray
{
private:
	Vec origin, direction;

public:

	Vec getOrigin() { return origin; }
	Vec getDirection() { return direction; }

	Ray();

	Ray(Vec, Vec);

	~Ray();
};

