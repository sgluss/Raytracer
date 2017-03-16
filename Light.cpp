#include "Light.h"

Light::Light()
{
	_position = Vec(0, 0, 0);
	_color = Color(1, 1, 1, 0);
}

Light::Light(Vec p, Color c)
{
	_position = p;
	_color = c;
}

Light::~Light()
{
}
