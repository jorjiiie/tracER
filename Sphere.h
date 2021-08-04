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
private:
	double radius;

	friend class Ray;
};