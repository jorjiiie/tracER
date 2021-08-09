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

	Sphere s4(0,0,0,5000);


	Sphere s5(25,-50,0,5);


	v3d direction(1,0,0);

	v3d up(0,-1,0);

	v3d origin(0,0,0);

	Camera cam(300,200,origin,up,direction,90);



	Lambertian BLACK(pix(0,0,0));
	Lambertian diffuse(pix(.5,.15,.35));
	Lambertian green(pix(.1,.8,.4));
	Lambertian light(pix(1,1,1));
	Metal shiniee(pix(.5,.5,.5),.3);


	light.set_emission(pix(2,2,2));	



	std::cout << s.get_radius() << " radius\n";
	v3d weird(1,.1,0);
	weird.normalize();
	Ray r(origin,weird);


	std::vector<tObject*> obj;
	obj.push_back(&s);
	obj.push_back(&s2);
	obj.push_back(&s3);
	obj.push_back(&s4);
	obj.push_back(&s5);

	s.set_material(diffuse);
	s2.set_material(green);
	s3.set_material(shiniee);
	s4.set_material(BLACK);
	s5.set_material(light);

	Scene sc(cam,obj);

	sc.render();
	std::cout << s.get_radius() << " radius\n";

	// std::cout << cr << "\n";
	// std::cout << cam << "\n";
	// r.intersect(s);
}