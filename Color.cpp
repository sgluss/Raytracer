#include "Color.h"

void Color::clip()
{
	double sum = _red + _green + _blue;
	double excess = sum - 3;

	if (excess > 0) {
		//	normalize out excess
		_red = _red + excess * (_red / sum);
		_green = _green + excess * (_green / sum);
		_blue = _blue + excess * (_blue / sum);
	}
	if (_red > 1) { _red = 1; }
	if (_green > 1) { _green = 1; }
	if (_blue > 1) { _blue = 1; }
	if (_red < 0) { _red = 0; }
	if (_green < 0) { _green = 0; }
	if (_blue < 0) { _blue = 0; }
}

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
