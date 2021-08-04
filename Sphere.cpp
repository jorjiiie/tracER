#pragma once
#include <iostream>
#include "Sphere.h"


// idk why this is a thing
Sphere::Sphere() {
	v3d d(0,0,0);
	position = d;
	radius = -1;
}

Sphere::Sphere(double x, double y, double z, double r) {
	v3d d(x,y,z);
	position = d;
	radius = r;
}
Sphere::Sphere(v3d& coords, double r) {
	position = coords;
	radius = r;	
}
double Sphere::get_radius() {
	return radius;
}

