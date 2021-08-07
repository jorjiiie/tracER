#pragma once
#include "v3d.h"

class Ray {
public:

	Ray();
	Ray(v3d&, v3d&);

	v3d get_position() const;
	v3d get_direction() const;
	// equation
	v3d direction, position;
};