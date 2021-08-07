#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "v3d.h"
#include "Ray.cpp"

/*
	Base object
	essentially contains the first point of an object (center for sphere ig and )
*/

class tObject {

public:
	tObject();
	tObject(double, double);
	void transform(int, int, int);
	virtual bool intersect(const Ray&, double&);
	virtual v3d get_normal(const v3d&);
protected:
	v3d position,rotation;
};