#pragma once
#include "v3d.h"

class Ray {
public:

	Ray();
	Ray(const v3d&, const v3d&);
	Ray(const Ray&);

	Ray& operator=(const Ray&);
	v3d get_position() const;
	v3d get_direction() const;
	// equation
	v3d direction, position;
};