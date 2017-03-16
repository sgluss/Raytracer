#include "Ray.h"

Ray::Ray()
{
	origin = Vec(0, 0, 0);
	direction = Vec(1, 0, 0);
}

Ray::Ray(Vec o, Vec d)
{
	origin = o;
	direction = d;
}

Ray::~Ray()
{
}
