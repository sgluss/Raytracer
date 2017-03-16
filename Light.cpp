#include "Light.h"

Light::Light()
{
	position = Vec(0, 0, 0);
	color = Color(1, 1, 1, 0);
}

Light::Light(Vec p, Color c)
{
	position = p;
	color = c;
}

Light::~Light()
{
}
