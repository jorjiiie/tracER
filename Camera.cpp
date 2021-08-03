#include "Camera.h"

Camera::Camera() {
	// why do i make default constructors
}

Camera::Camera(int w, int h, v3d up, v3d target, double angle) {
	// im not dealing with odd dimensions 
	// round down
	width = w & 0xfffffffe;
	height = h & 0xfffffffe; 

	this->up = up;
	direction = target;
	this->angle = angle;
}


std::ostream& operator<<(std::ostream& stream, Camera& cam) {
	stream << "[Camera: " << cam.width << "x " << cam.height << " up: " << cam.up << " direction: " << cam.direction << " angle: " << cam.angle << "]";
	return stream;
}