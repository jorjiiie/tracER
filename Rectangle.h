#pragma once

#include "tObject.cpp"

// light is just sphere but with big


class Rectangle : public tObject {
public:
	Rectangle();
	Rectangle(double _a1, double _a2, double _b1, double _b2, double _c, int _type) : a1(_a1), a2(_a2), b1(_b1), b2(_b2), c(_c), type(_type) {};
	virtual bool intersect(const Ray&, double&);
	virtual v3d get_normal(const v3d&);
	virtual void minmax_points(v3d&, v3d&);

	// if c is x then its yz
	// if c is z then its xy
	// if c is y then its xz
	double a1,a2,b1,b2,c;
	// 1 is x, 2 is y, 3 is z
	int type;
};