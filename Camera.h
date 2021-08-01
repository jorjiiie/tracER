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
	vector<vector<pix> > render();
	vector<vector<pix> > render(int);

	// i dont know what else i need
private:
	int width,length;
	// how do i do the projection thing
	// its like camera at a point and then project a rectangle forwards and shoot rays through it
	// for each px shoot #SAMPLES rays and average the brightness for rgb
		
};