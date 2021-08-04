#pragma once
#include <cmath>
#include <iostream>


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
	v3d(const v3d& o) {
		x = o.x;
		y = o.y;
		z = o.z;
	}

	v3d& operator=(const v3d o) {
		x=o.x;
		y=o.y;
		z=o.z;
		return *this;
	}


	v3d operator+(const v3d& o) {
		v3d tmp = *this;
		return tmp += o;
	}
	v3d& operator+=(const v3d& o) {
		this->x += o.x;
		this->y += o.y;
		this->z += o.z;
		return *this;
	}
	v3d operator-(const v3d& o) {
		v3d tmp = *this;
		return tmp -= o;
	}
	v3d& operator-=(const v3d& o) {
		this->x -= o.x;
		this->y -= o.y;
		this->z -= o.z;
		return *this;
	}	


	double operator*(v3d& o) {
		return this->x * o.x + this->y * o.y + this->z * o.z;
	}

	v3d operator*(double x) {
		v3d tmp = *this;
		return tmp *= x;
	}
	v3d& operator*=(double x) {
		this->x *= x;
		this->y *= x;
		this->z *= x;
		return *this;
	}

	v3d cross(v3d& o) {
		//cross product
		v3d cp;
		cp.x = this->y * o.z - this->z * o.y;
		cp.y = this->x * o.z - this->z * o.x;
		cp.z = this->x * o.y - this->y * o.x;

		return cp;
	}

	v3d& to_unit() {
		double magnitude = std::sqrt(x*x + y*y + z*z);
		// needs to divide everything by sqrt magnitude

		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
		return *this;
	}

};

std::ostream& operator<<(std::ostream& stream, const v3d& vec) {
	stream << "[v3d (" << vec.x << ", " << vec.y << ", " << vec.z << ")]";
	return stream;
}