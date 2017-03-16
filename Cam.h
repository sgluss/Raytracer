#pragma once

#include "Vec.h"

class Cam
{
private:
	Vec camPosition, camDirection, camRight, camDown;

public:

	Vec getCamPosition() { return camPosition; }
	Vec getCamDirection() { return camDirection; }
	Vec getCamRight() { return camRight; }
	Vec getCamDown() { return camDown; }

	Cam();

	Cam(Vec, Vec, Vec, Vec);

	~Cam();
};