#include "Scene.cpp"

int main() {


	// for (int i=0;i<50;i++) {
		// std::cout << (rand() * 1.0 / RAND_MAX * 2 - 1 ) << " ";
	// }
	// std::cout << "\n";

	std::freopen("out.txt","w",stderr);

	Sphere s(35,-5,15,15);

	Sphere s2(0,505,0,500);

	Sphere s3(35,-5,-15,15);

	v3d direction(1,0,0);

	v3d up(0,0,1);

	v3d origin(0,0,0);

	Camera cam(500,500,origin,up,direction,90);



	Lambertian diffuse(pix(.5,.15,.35));
	Lambertian green(pix(.1,.8,.4));
	Metal shiniee(pix(.8,.8,.8),.1);

	std::cout << s.get_radius() << " radius\n";
	v3d weird(1,.1,0);
	weird.normalize();
	Ray r(origin,weird);


	std::vector<tObject*> obj;
	obj.push_back(&s);
	obj.push_back(&s2);
	obj.push_back(&s3);

	s.set_material(diffuse);
	s2.set_material(green);
	s3.set_material(shiniee);
	Scene sc(cam,obj);

	sc.render();
	std::cout << s.get_radius() << " radius\n";

	// std::cout << cr << "\n";
	// std::cout << cam << "\n";
	// r.intersect(s);
}