#pragma once

#include <time.h>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <thread>
#include <queue>

#include "tUtility.cpp"
#include "tObject.cpp"
#include "Camera.cpp"
#include "Ray.cpp"
#include "Materials.h"
#include "Shapes.h"
#include "pix.h" 
#include "BVH_node.cpp"

#define PI 3.14159265
#define SAMPLES 500
#define MAX_BOUNCES 5
#define DEBUG_MODE 1
#define FAR_CLIP 100000000
#define NEAR_CLIP .01


class Scene {

public:
	Scene();
	Scene(Camera, std::vector<tObject*>);
	void render_main(std::vector<std::vector<v3d> >&, std::vector<std::vector<pix> >&, std::vector<std::vector<int> >&, v3d&, v3d&, int, std::vector<int>&, int);
	void single_pass();
	void render();
	tObject* BVH_intersect(const Ray&, double&);
	tObject* intersect(const Ray&, double&);
	pix trace(const Ray, int);
	pix rrtrace(const Ray, int, double);
	void build_BVH();
private:
	Camera cam;

	std::vector<tObject*> scene_objects;
	tObject* bbox;
};