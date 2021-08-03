#pragma once
#include <iostream>
#include "tObject.cpp"
#include "Ray.cpp"


struct pix {
	int r,g,b;
}
class Camera : public tObject {

public:
	Camera();
	Camera(double, double);
	// default i have no idea how many samples
	vector<vector<pix> > render();
	// int for # samples
	vector<vector<pix> > render(int);

	// i dont know what else i need
private:
	int width,length;
	// unit vector that points up (analagous to rotation but makes it ez for computation <3)
	v3d up;

	// how do i do the projection thing
	// its like camera at a point and then project a rectangle forwards and shoot rays through it
	// for each px shoot #SAMPLES rays and average the brightness for rgb
		
};