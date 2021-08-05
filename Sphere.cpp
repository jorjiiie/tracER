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

bool Sphere::intersect(const Ray& r) {
	// maths time
	/*
		solving directly using parametric
		t = -(v * d) +/- sqrt((v*d) - (v^2 - r^2))
	*/

	v3d math_v = r.get_position();
	math_v -= position;

	v3d direction = r.get_direction();
	double front = - (math_v * direction);

	double inside = front*front - (math_v * math_v - radius * radius);


	if (inside < 0) {
		// std::cout << "NO INTERSECTION: " << math_v*math_v << " " << s.radius << " " << front << " " << inside << "\n";
		return 0;
	}

	double back = std::sqrt(inside);

	double t1 = front + back;
	double t2 = front - back;

	/*
	std::cout << "CAST RAY : [" << (this->direction) << " " << this->position << "]: ";
	printf("front is %f back is %f so t1 and t2 are %f and %f\n",front,back,t1,t2);
	*/
	return true;
}