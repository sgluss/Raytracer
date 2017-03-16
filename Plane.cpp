#include "Plane.h"

Plane::Plane()
{
	_normal = Vec(1, 0, 0);
	_distance = 0;
	_color = Color(0.5, 0.5, 0.5, 0);
}

Plane::Plane(Vec normal, double distance, Color color)
{
	_normal = normal;
	_distance = distance;
	_color = color;
}

Plane::~Plane()
{
}