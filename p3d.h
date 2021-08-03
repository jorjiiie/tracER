#pragma once


struct p3d {
	// essentially a vector? but not a 'vector'

	// yes p3d and v3d are literally the same except p3d is missing some functions
	double x,y,z;
	p3d() {
		x=y=z=0;
	}

	p3d(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	p3d(const v3d& o) {
		x = o.x;
		y = o.y;
		z = o.z;
	}

	p3d& operator=(const v3d o) {
		x=o.x;
		y=o.y;
		z=o.z;
		return *this;
	}


	p3d operator+(v3d& o) {
		v3d tmp = *this;
		return tmp += o;
	}

	p3d& operator+=(v3d& o) {
		this->x += o.x;
		this->y += o.y;
		this->z += o.z;
		return *this;
	}
	p3d operator-(v3d& o) {
		v3d tmp = *this;
		return tmp -= o;
	}
	p3d& operator-=(v3d& o) {
		this->x -= o.x;
		this->y -= o.y;
		this->z -= o.z;
		return *this;
	}
};