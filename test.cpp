#include "Scene.cpp"

int main() {

	std::freopen("out.txt","w",stderr);
	Sphere s(36,0,0,25);

	v3d position(0,25,0);

	// HAS TO BE UNIT

	v3d direction(15,0,0);
	direction.to_unit();
	Ray r(position,direction);

	v3d oth(0,10,0);

	v3d cr = oth.cross(direction);

	v3d up(0,0,1);
	Camera cam(10,10,up,direction,90);

	std::vector<tObject> obj;
	obj.push_back(s);

	Scene sc(cam,obj);

	sc.render();

	std::cout << cr << "\n";
	std::cout << cam << "\n";
	r.intersect(s);
}