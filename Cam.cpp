#include "Cam.h"

Cam::Cam()
{
	_camPosition = Vec(0, 0, 0);
	_camDirection = Vec(0, 0, 1);
	_camRight = Vec(0, 0, 0);
	_camDown = Vec(0, 0, 0);
}

Cam::Cam(Vec pos, Vec dir, Vec r, Vec d)
{
	_camPosition = pos;
	_camDirection = dir;
	_camRight = r;
	_camDown = d;
}

Cam::~Cam()
{
}