#pragma once

#include "Triangle.h"

Triangle::Triangle() {

}
bool Triangle::intersect(const Ray& r, double& time_out) {
	// ripped right off wikipedia :D
	v3d edge1,edge2, h, s, q;
	double a,f,u,v;

	edge1 = vertex_b - vertex_a;
	edge2 = vertex_c - vertex_a;
	h = r.direction.cross(edge2);
	a = edge1 * h;


	if (std::abs(a) < .0001) 
		return false; // parallel apparently lol

	f = 1.0/a;
	s = r.position - vertex_a;
	u = f * (s * h);

	if (u < 0.0 || u > 1.0) 
		return false;

	q = s.cross(edge1);
	v = f * (r.direction * q);

	if (v < 0.0 || u + v > 1.0)
		return false;

	double t = f * (edge2 * q);
	if (t > .0001) {
		time_out = t;
		return true;
	}
	return false;

}

v3d Triangle::get_normal(const v3d& p) {
	// cross product of a->b and a->c
	// std::cout << ((vertex_a - vertex_b).cross(vertex_c - vertex_b)).normalize() << "\n";
	return ((vertex_a - vertex_b).cross(vertex_c - vertex_b)).normalize();
}

void Triangle::minmax_points(v3d& min, v3d& max) {
	min = tUtility::min(vertex_a, tUtility::min(vertex_b, vertex_c));
	max = tUtility::max(vertex_a, tUtility::max(vertex_b, vertex_c));
}