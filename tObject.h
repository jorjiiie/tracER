#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "v3d.h"


/*
	Base object
	essentially contains the first point of an object (center for sphere ig and )
*/


class tObject {

public:
	tObject();
	tObject(double, double);
	void transform(int, int, int);
protected:
	v3d position,rotation;
};