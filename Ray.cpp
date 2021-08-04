#pragma once
#include "Ray.h"
#include "v3d.h"

Ray::Ray() {
	// for arrays lets go
}
Ray::Ray(v3d& pos, v3d& dir) {
	position = pos;
	direction = dir;

}

bool Ray::intersect(const Sphere& s) {
	// maths time
	/*
		solving directly using parametric
		t = -(v * d) +/- sqrt((v*d) - (v^2 - r^2))
	*/

	v3d math_v = position;
	math_v -= s.position;

	double front = - (math_v * direction) ;

	double inside = front*front - (math_v * math_v - s.radius * s.radius);


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