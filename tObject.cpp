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
Material* tObject::get_material() {
	return material;
}
void tObject::set_material(Material& m) {
	material = &m;
}
void tObject::minmax_points(v3d& min, v3d& max) {
	min = v3d(0,0,0);
	max = v3d(0,0,0);
}

void tObject::bounded_children(tObject* l, tObject* r) {
	// assumes is 
}

bool tObject::operator<(const tObject& o) const {
	return position.x < o.position.x;
}