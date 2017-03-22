#include "Sphere.h"

double Sphere::findIntersection(Ray ray)
{
	Vec rayOrigin = ray.getOrigin();
	double rayOriginX = rayOrigin.getX();
	double rayOriginY = rayOrigin.getY();
	double rayOriginZ = rayOrigin.getZ();

	Vec rayDirection = ray.getDirection();
	double rayDirectionX = rayDirection.getX();
	double rayDirectionY = rayDirection.getY();
	double rayDirectionZ = rayDirection.getZ();

	double sphereCenterX = _center.getX();
	double sphereCenterY = _center.getY();
	double sphereCenterZ = _center.getZ();

	double a = 1;
	double b = (2 * (rayOriginX - sphereCenterX) * rayDirectionX) +
				(2 * (rayOriginY - sphereCenterY) * rayDirectionY) +
				(2 * (rayOriginZ - sphereCenterZ) * rayDirectionZ);

	double c = pow(rayOriginX - sphereCenterX, 2) +
		pow(rayOriginY - sphereCenterY, 2) +
		pow(rayOriginZ - sphereCenterZ, 2) -
		(_radius*_radius);

	double discriminant = b * b - 4 * c;
	double root;

	if (discriminant > 0) {
		//	The ray intersects the sphere
		//	The first root. Magic number at end helps with accuracy errors
		//	This ensures that all intersections are on the outside of the sphere surface
		root = ((-1 * b - sqrt(discriminant)) / 2) - 0.000001;

		if (root > 0) {
			//	First root is smallest possible root
			return root;
		}
		else {
			//	Then the second root is the smallest positive root
			root = ((sqrt(discriminant) - b) / 2) - 0.000001;
			return root;
		}
	}
	else
	{
		//	The ray misses the sphere
		return -1;
	}
}

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