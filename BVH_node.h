#pragma once

#include <vector>

#include "tObject.cpp"
/*
	BVH node for BVH
	has left,right, then minmax of its points
*/
class BVH_node : public tObject {

public:
	BVH_node();
	BVH_node(tObject&, tObject&);
	BVH_node(tObject*, tObject*);
	virtual bool intersect(const Ray&, double&);
	virtual v3d get_normal(const v3d&);
	// min xyz and max xyz for bb
	virtual void minmax_points(v3d&, v3d&);

	tObject *left,*right;
	v3d min, max;
	// int hit_cnt=0;
};