#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>


#include "tObject.cpp"
#include "Camera.cpp"
#include "Ray.cpp"
#include "Sphere.cpp"

#define PI 3.14159265
#define SAMPLES 100

class Scene {

public:
	Scene();
	Scene(Camera, std::vector<tObject*>);
	void render();
	tObject closest_intersection(Ray);
	pix trace(Ray, int);
private:
	Camera cam;

	// i guess we just have lights in here + others
	// lights are just emissive things uwu
	std::vector<tObject*> scene_objects;
};