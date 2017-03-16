#include "Ray.h"

Ray::Ray()
{
	_origin = Vec(0, 0, 0);
	_direction = Vec(1, 0, 0);
}

Ray::Ray(Vec o, Vec d)
{
	_origin = o;
	_direction = d;
}

Ray::~Ray()
{
}
