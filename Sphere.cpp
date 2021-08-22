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

bool Sphere::intersect(const Ray& r, double& t) {
	// maths time
	/*
		solving directly using parametric
		t = -(v * d) +/- sqrt((v*d) - (v^2 - r^2))
	*/

	v3d math_v = r.position;
	math_v -= position;

	v3d direction = r.direction;
	double front = - (math_v * direction);

	double inside = front*front - (math_v * math_v - radius * radius);


	if (inside < 0) {
		// std::cout << "NO INTERSECTION: " << math_v*math_v << " " << s.radius << " " << front << " " << inside << "\n";
		return 0;
	}

	double back = std::sqrt(inside);

	double t1 = front + back;
	double t2 = front - back;

	double mx = std::max(t1,t2);

	// not in this direction
	if (mx<=0) return false;

	double mn = std::min(t1,t2);

	// if its in the middle then yadyada
	if (mn<=0) t = mx;
	else t = mn;

	/*
	std::cout << "CAST RAY : [" << (this->direction) << " " << this->position << "]: ";
	printf("front is %f back is %f so t1 and t2 are %f and %f\n",front,back,t1,t2);
	*/
	return true;
}

v3d Sphere::get_normal(const v3d& p) {
	// vector center->p is p-center, and we normalize it because we r cool 
	return (position-p).normalize();
}