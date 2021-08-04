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
// i'm going to suffer when cube is a thing
enum RENDER_TYPE {SPHERE, CUBE};

class tObject {

public:
	tObject();
	tObject(double, double);
	void transform(int, int, int);
protected:
	v3d position,rotation;
// public:
	// const RENDER_TYPE TYPE;
};