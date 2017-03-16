#pragma once

#include "Vec.h"

class Cam
{
private:
	Vec _camPosition, _camDirection, _camRight, _camDown;

public:

	Vec getCamPosition() { return _camPosition; }
	Vec getCamDirection() { return _camDirection; }
	Vec getCamRight() { return _camRight; }
	Vec getCamDown() { return _camDown; }

	Cam();

	Cam(Vec, Vec, Vec, Vec);

	~Cam();
};