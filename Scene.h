#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "tObject.cpp"
#include "Camera.cpp"
#include "Ray.cpp"
#include "Sphere.cpp"


class Scene {
public:
	Scene();
	void render();
	tObject closest_intersection(Ray);
	pix trace(Ray, int);
private:
	Camera cam;

	// i guess we just have lights in here + others
	// lights are just emissive things uwu
	vector<tObject> scene_objects;
}