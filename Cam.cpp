#include "Cam.h"

Cam::Cam()
{
	camPosition = Vec(0, 0, 0);
	camDirection = Vec(0, 0, 1);
	camRight = Vec(0, 0, 0);
	camDown = Vec(0, 0, 0);
}

Cam::Cam(Vec pos, Vec dir, Vec r, Vec d)
{
	camPosition = pos;
	camDirection = dir;
	camRight = r;
	camDown = d;
}

Cam::~Cam()
{
}