#include "Sphere.h"

Sphere::Sphere()
{
	_center = Vec(0, 0, 0);
	_radius = 1.0;
	_color = Color(0.5, 0.5, 0.5, 0);
}

Sphere::Sphere(Vec newCenter, double newRad, Color newColor)
{
	_center = newCenter;
	_radius = newRad;
	_color = newColor;
}

Sphere::~Sphere()
{
}