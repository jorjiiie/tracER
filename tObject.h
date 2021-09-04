#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include "v3d.h"
#include "Ray.cpp"
#include "Material.cpp"
/*
	Base object
	essentially contains the first point of an object (center for sphere ig and )
*/

class tObject {

public:
	tObject();
	tObject(double, double);
	void transform(int, int, int);
	Material* get_material();
	void set_material(Material& m);
	void set_viewport(const pix& col) {viewport_col = col;}
	pix get_viewport() {return viewport_col;}
	virtual bool intersect(const Ray&, double&);
	virtual v3d get_normal(const v3d&);
	virtual void minmax_points(v3d&, v3d&);
	virtual void bounded_children(tObject*, tObject*);
	bool is_BVH() {return bvh;}
	bool operator<(const tObject&) const;
protected:
	v3d position,rotation;
	Material* material;
	bool bvh = false;
	pix viewport_col = pix(1,1,1);
};

