#pragma once
#include "tObject.cpp"
#include "Sphere.h"


class Ray {
public:
	Ray();
	Ray(v3d&, v3d&);
	bool intersect(const Sphere&);

private:
	// equation
	v3d direction, position;


};