#pragma once

#include "tObject.cpp"

// light is just sphere but with big


class Sphere : public tObject {
public:
	Sphere();
	Sphere(double, double, double, double);
	Sphere(v3d&, double);
	double get_radius();
	virtual bool intersect(const Ray&, double&);
	virtual v3d get_normal(const v3d&);
	virtual void minmax_points(v3d&, v3d&);
private:
	double radius;
};