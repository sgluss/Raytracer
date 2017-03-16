#pragma once

#include "Vec.h"

class Ray
{
private:
	Vec _origin, _direction;

public:

	Vec getOrigin() { return _origin; }
	Vec getDirection() { return _direction; }

	Ray();

	Ray(Vec, Vec);

	~Ray();
};

