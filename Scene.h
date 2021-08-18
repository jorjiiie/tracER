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
#include "Sphere.cpp"
#include "pix.h" 
#include "Materials.h"

#define PI 3.14159265
#define SAMPLES 1000
// since lights are hit by chance (and no shadow rays), this is actually max_bounces + 1 so MAX_BOUNCES = 1 will get you a black screen
#define MAX_BOUNCES 5
#define DEBUG_MODE 1
class Scene {

public:
	Scene();
	Scene(Camera, std::vector<tObject*>);
	void render_main(std::vector<std::vector<v3d> >&, std::vector<std::vector<pix> >&, std::vector<std::vector<int> >&, v3d&, v3d&, int, std::vector<int>&, int);
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