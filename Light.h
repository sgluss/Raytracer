#pragma once

#include "Vec.h"
#include "Color.h"

class Light
{
private:
	Vec position;
	Color color;

public:

	Vec getPosition() { return position; }
	Color getColor() { return color; }

	Light();

	Light(Vec, Color);

	~Light();
};