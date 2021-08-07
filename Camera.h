#pragma once
#include <iostream>
#include <cmath>
#include "tObject.cpp"
#include "Ray.cpp"



struct pix {
	double r,g,b;
	pix() {
		r=g=b=0.0;
	}
	pix(double r, double g, double b) {
		this->r=r;
		this->g=g;
		this->b=b;
	}
	pix operator+(const pix& o) {
		pix tmp = *this;
		return tmp+=o;
	}
	pix& operator+=(const pix& o) {
		r+=o.r;
		g+=o.g;
		b+=o.b;
		return *this;
	}
	pix operator*(double d) {
		pix tmp = *this;
		return tmp*=d;
	}
	pix& operator*=(double d) {
		r*=d;
		g*=d;
		b*=d;
		return *this;
	}
	pix operator/(double d) {
		pix tmp = *this;
		return tmp/=d;
	}
	pix& operator/=(double d) {
		r/=d;
		g/=d;
		b/=d;
		return *this;
	}
	void gamma_correct(int samples) {
		// idk why gamma correction is a thing
		double scale = 1.0 / samples;
		r = std::sqrt(scale * r);
		g = std::sqrt(scale * g);
		b = std::sqrt(scale * b);
	}
};

class Camera : public tObject {

public: // all public because used by Scene and I'm not using get/set for everything
	Camera();
	Camera(int, int, v3d, v3d, v3d, double);

	int width, height;
	// unit vector that points up (analagous to rotation but makes it ez for computation <3)
	v3d position,up, direction;

	// how wide the shot is
	double angle;		
};