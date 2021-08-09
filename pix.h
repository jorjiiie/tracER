#pragma once
#include <cmath>

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
	pix operator*(const pix& o) const {
		pix tmp = *this;
		return tmp *= o;
	}
	pix& operator*=(const pix& o) {
		r*=o.r;
		g*=o.g;
		b*=o.b;
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