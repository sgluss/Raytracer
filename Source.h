#pragma once

#include "Vec.h"
#include "Color.h"

class Source
{
public:

	virtual Vec getLightPosition() {
		return Vec(0, 0, 0);
	}

	virtual Color getColor() {
		return Color(1, 1, 1, 0);
	}

	Source();
	~Source();
};

