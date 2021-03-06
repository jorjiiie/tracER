#pragma once
#include <iostream>
#include <cmath>
#include "tObject.cpp"
#include "Ray.cpp"


class Camera : public tObject {

public: // all public because used by Scene and I'm not using get/set for everything
	Camera();
	Camera(int, int, v3d, v3d, v3d, double, double, double);

	int width, height;
	// unit vector that points up (analagous to rotation but makes it ez for computation <3)
	v3d position,up, direction;

	// how wide the shot is
	double angle;
	double apeture;
	double focus;
};