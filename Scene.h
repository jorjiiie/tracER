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
#define SAMPLES 1000

class Scene {

public:
	Scene();
	Scene(Camera, std::vector<tObject*>);
	void render();
	v3d uniform_hemisphere(const v3d&, const v3d&, const v3d&);
	// tmp lOL
	v3d uniform_sphere();
	tObject* closest_intersection(Ray);
	// ray traveling and the depth
	pix trace(const Ray, int);
private:
	Camera cam;

	// i guess we just have lights in here + others
	// lights are just emissive things uwu

	// change this into shared_ptr<tObject> some time !!!
	std::vector<tObject*> scene_objects;
};