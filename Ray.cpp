#pragma once
#include "Ray.h"

Ray::Ray() {
	// for arrays lets go
}
Ray::Ray(v3d& pos, v3d& dir) {
	position = pos;
	direction = dir;

}

v3d Ray::get_position() const {
	return position;
}
v3d Ray::get_direction() const {
	return direction;
}