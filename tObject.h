#pragma once
#include <iostream>
#include <math>
#include <algorithm>
#include <vector>

using namespace std;

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
	double pos[3];
	double rot[3]; // no clue how to calc this btw
};