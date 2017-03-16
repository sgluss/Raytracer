#include "Color.h"

Color::Color()
{
	_red = 0.5;
	_green = 0.5;
	_blue = 0.5;
}

Color::Color(double r, double g, double b, double s)
{
	_red = r;
	_green = g;
	_blue = b;
	_special = s;
}

Color::~Color()
{
}
