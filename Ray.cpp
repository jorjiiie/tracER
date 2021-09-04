#pragma once
#include "Ray.h"

Ray::Ray() {
	// for arrays lets go
}
Ray::Ray(const Ray& o) {
	position = o.position;
	direction = o.direction;
}
Ray::Ray(const v3d& pos, const v3d& dir) {
	position = pos;
	direction = dir;
	direction.normalize();

}


Ray& Ray::operator=(const Ray& r) {
	position = r.position;
	direction = r.direction;
	return *this;
}
std::ostream& operator<<(std::ostream& stream, const Ray& r) {
	stream << "[Ray: " << r.position << " " << r.direction << "]";
	return stream;
}