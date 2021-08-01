#pragma once
#include <cmath>

struct v3d {
	double x,y,z;

	v3d() {
		x=y=z=0;
	}

	v3d(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	v3d(v3d& o) {
		x = o.x;
		y = o.y;
		z = o.z;
	}
	v3d& operator=(v3d o) {
		x=o.x;
		y=o.y;
		z=o.z;
		return *this;
	}

	v3d operator+(v3d& o) {
		v3d tmp = *this;
		return tmp += o;
	}

	v3d& operator+=(v3d& o) {
		this->x += o.x;
		this->y += o.y;
		this->z += o.z;
		return *this;
	}

	double operator*(v3d& o) {
		return this->x * o.x + this->y * o.y + this->z * o.z;
	}

	void to_unit() {
		double magnitude = std::sqrt(x*x + y*y + z*z);
		// needs to divide everything by sqrt magnitude

		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

};