#pragma once

#include <time.h>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <thread>

#include "tUtility.cpp"
#include "tObject.cpp"
#include "Camera.cpp"
#include "Ray.cpp"
#include "Materials.h"
#include "Sphere.cpp"
#include "Rectangle.cpp"
#include "pix.h" 


#define PI 3.14159265
#define SAMPLES 750
#define MAX_BOUNCES 8
#define DEBUG_MODE 1
class Scene {

public:
	Scene();
	Scene(Camera, std::vector<tObject*>);
	void render_main(std::vector<std::vector<v3d> >&, std::vector<std::vector<pix> >&, std::vector<std::vector<int> >&, v3d&, v3d&, int, std::vector<int>&, int);
	void render();
	void single_pass();
	pix trace(const Ray, int);
	pix rrtrace(const Ray, int, double);
private:
	Camera cam;

	// change this into shared_ptr<tObject> some time !!!
	std::vector<tObject*> scene_objects;
};