#pragma once
#include <iostream>
#include "tObject.cpp"

// light is just sphere but with big


class Sphere : public tObject {
public:
	Sphere();
	Sphere(double, double, double, double);
	Sphere(v3d&, double);
	double get_radius();
	bool intersect(const Ray&, double&);
	v3d get_normal(const v3d&);
private:
	double radius;
};