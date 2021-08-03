#include "Ray.cpp"
#include "Sphere.cpp"

int main() {
	Sphere s(36,0,0,25);

	v3d position(0,25,0);
	
	// HAS TO BE UNIT

	v3d direction(1,0,0);
	direction.to_unit();
	Ray r(position,direction);

	r.intersect(s);
}