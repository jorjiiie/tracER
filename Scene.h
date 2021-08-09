#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>

#include "tUtility.cpp"
#include "tObject.cpp"
#include "Camera.cpp"
#include "Ray.cpp"
#include "Sphere.cpp"
#include "pix.h" 
#include "Materials.h"

#define PI 3.14159265
#define SAMPLES 20

class Scene {

public:
	Scene();
	Scene(Camera, std::vector<tObject*>);
	void render();

	// ray traveling and the depth
	pix trace(const Ray, int);
private:
	Camera cam;

	// i guess we just have lights in here + others
	// lights are just emissive things uwu

	// change this into shared_ptr<tObject> some time !!!
	std::vector<tObject*> scene_objects;
};