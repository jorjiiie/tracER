#pragma once

#include "Rectangle.h"

Rectangle::Rectangle() {
	//hi
}

bool Rectangle::intersect(const Ray& ray, double& time_out) {
	// switch on the type and then determine something
	double min_a = std::min(a1,a2);
	double max_a = std::max(a1,a2);

	double min_b = std::min(b1,b2);
	double max_b = std::max(b1,b2);

	double t;

	double dm[3] = {ray.direction.x, ray.direction.y, ray.direction.z};
	double rp[3] = {ray.position.x, ray.position.y , ray.position.z};
	int index[2];
	if (type == 1) {
		t = (c - ray.position.x) / ray.direction.x;
		index[0]=1;
		index[1]=2;
	} else if (type == 2) {
		t = (c - ray.position.y) / ray.direction.y;
		index[0]=0;
		index[1]=2;
	} else {
		t = (c - ray.position.z) / ray.direction.z;
		index[0]=0;
		index[1]=1;
	}

	if (t<0) return false;
	// check bounds for a and b
	double new_a = dm[index[0]] * t + rp[index[0]];
	double new_b = dm[index[1]] * t + rp[index[1]];

	if (new_a < min_a || new_a > max_a || new_b < min_b || new_b > max_b) return false;

	time_out = t;
	// std::cout << c << "\n";
	return true;
}

v3d Rectangle::get_normal(const v3d& p) {
	// need to know which direction... 
	switch(type) {
		case 1:
			return v3d(1,0,0);
		case 2:
			return v3d(0,1,0);
		case 3:
			return v3d(0,0,1);
	}
	return v3d(0,0,0);
}