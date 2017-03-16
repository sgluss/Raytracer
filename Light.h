#pragma once

#include "Vec.h"
#include "Color.h"

class Light
{
private:
	Vec _position;
	Color _color;

public:

	Vec getPosition() { return _position; }
	Color getColor() { return _color; }

	Light();

	Light(Vec, Color);

	~Light();
};