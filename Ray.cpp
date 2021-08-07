#pragma once
#include "Ray.h"

Ray::Ray() {
	// for arrays lets go
}
Ray::Ray(v3d& pos, v3d& dir) {
	position = pos;
	direction = dir;

}
