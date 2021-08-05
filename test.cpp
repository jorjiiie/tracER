#include "Scene.cpp"

int main() {


	// for (int i=0;i<50;i++) {
		// std::cout << (rand() * 1.0 / RAND_MAX * 2 - 1 ) << " ";
	// }
	// std::cout << "\n";

	std::freopen("out.txt","w",stderr);

	Sphere s(25,5,5,15);

	v3d direction(1,0,0);

	v3d up(0,0,1);

	v3d origin(0,0,0);

	Camera cam(300,300,origin,up,direction,90);

	std::cout << s.get_radius() << " radius\n";
	v3d weird(1,.1,0);
	weird.to_unit();
	Ray r(origin,weird);

	std::cout << s.intersect(r) << " JASLDJKASD\n";

	std::vector<tObject*> obj;
	obj.push_back(&s);

	Scene sc(cam,obj);

	sc.render();
	std::cout << s.get_radius() << " radius\n";

	// std::cout << cr << "\n";
	// std::cout << cam << "\n";
	// r.intersect(s);
}