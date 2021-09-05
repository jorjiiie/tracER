#pragma once

#include "tObject.cpp"


class Triangle : public tObject {

public:
	Triangle();
	Triangle(const v3d& _a, const v3d& _b, const v3d& _c) : vertex_a(_a), vertex_b(_b), vertex_c(_c) {};

	virtual bool intersect(const Ray&, double&);
	virtual v3d get_normal(const v3d&);
	virtual void minmax_points(v3d&, v3d&);

	v3d vertex_a, vertex_b, vertex_c;
};