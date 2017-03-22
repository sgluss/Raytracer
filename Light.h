#pragma once

#include "Source.h"
#include "Vec.h"
#include "Color.h"

class Light : public Source
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