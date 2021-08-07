#pragma once
#include "tObject.h"


tObject::tObject() {
	
}

bool tObject::intersect(const Ray& r, double& t) {
	return false;
}
v3d tObject::get_normal(const v3d& p) {
	return v3d(0,0,0);
}