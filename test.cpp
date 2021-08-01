#include "Ray.cpp"
#include "Sphere.cpp"

int main() {
	Sphere s(0,0,0,25);

	v3d position(0,0,0);
	// HAS TO BE UNIT

	v3d direction(69,69,69420);
	direction.to_unit();
	Ray r(position,direction);

	r.intersect(s);
}