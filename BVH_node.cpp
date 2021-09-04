#pragma once

#include "BVH_node.h"
#include "tUtility.cpp"
// split into bvh and aabb
BVH_node::BVH_node() {

}
BVH_node::BVH_node(tObject& l, tObject& r) {
	left = &l;
	right = &r;
	v3d l_mmx[2], r_mmx[2];
	l.minmax_points(l_mmx[0], l_mmx[1]);
	r.minmax_points(r_mmx[0], r_mmx[1]);

	min = tUtility::min(l_mmx[0], r_mmx[0]);
	max = tUtility::max(l_mmx[1], r_mmx[1]);

	bvh = true;
}
BVH_node::BVH_node(tObject* l, tObject* r) {
	left = l;
	right = r;
	v3d l_mmx[2], r_mmx[2];
	l->minmax_points(l_mmx[0], l_mmx[1]);
	r->minmax_points(r_mmx[0], r_mmx[1]);

	min = tUtility::min(l_mmx[0], r_mmx[0]);
	max = tUtility::max(l_mmx[1], r_mmx[1]);

	bvh = true;
}
bool BVH_node::intersect(const Ray& ray, double& time_out) {
	double min_time = .01;
	double max_time = 10000000;
	for (int i=0;i<3;i++) {
		double mn = (min[i]-ray.position[i])/ray.direction[i];
		double mx = (max[i]-ray.position[i])/ray.direction[i];
		if (mn>mx) 
			std::swap(mn,mx);
		if (mn>min_time) min_time = mn;
		if (mx<max_time) max_time = mx;
		if (max_time - min_time < -.001) return false;
	}
	return min_time <= max_time || std::abs(min_time-max_time) < .0001;
}

v3d BVH_node::get_normal(const v3d& p) {
	// lOL
	return v3d(0,0,0);
}
void BVH_node::minmax_points(v3d& min, v3d& max) {
	min = this->min;
	max = this->max;
}
