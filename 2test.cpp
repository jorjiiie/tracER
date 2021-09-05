#include "Scene.cpp"

int main(int argc, char * argv[]) {


	// for (int i=0;i<50;i++) {
		// std::cout << (rand() * 1.0 / RAND_MAX * 2 - 1 ) << " ";
	// }
	// std::cout << "\n";

	std::freopen("out.txt","w",stderr);

	// search is O(n) for now lol
	// with bvh it will go down to O(logn) i think

	// test();
	// return 0;

	Sphere s6(10,5,3,5);
	Sphere s1(5,7,-3,3);

	Rectangle rect(10,-10,-10,10,20,1);
	Rectangle r2(20,0,10,-10,10,2);
	Rectangle r3(20,0,10,-10,-10,2);
	Rectangle r4(20,0,-10,10,10,3);
	Rectangle r5(20,0,-10,10,-10,3);
	Rectangle r7(2,7,2,-2,-9.9,2);
	Rectangle backboard(-100,100,-100,100,-10,1);
	v3d direction(1,0,0);

	v3d up(0,-1,0);

	v3d origin(-8,0,0);

	Camera cam(200,150,origin,up,direction,110,0,69);

	Lambertian BLACK(pix(0,0,0));
	Lambertian diffuse(pix(.2,.2,.2));
	// Lambertian green(pix(.1,.8,.4));
	Lambertian light(pix(1.5,1.5,1.5));
	Lambertian grey(pix(.6,.6,.6));
	Metal shiniee(pix(1,1,1),0.1);
	Metal perfect(pix(1,1,1),0);

	Lambertian red(pix(.8,.2,.2));
	Lambertian green(pix(.2,.8,.2));
	light.set_emission(pix(20,20,20));	

	Lambertian red2(pix(.8,.2,.2));
	// red2.set_emission(pix(.5,.5,.5));


	v3d v0(10,-6,-6);
	v3d v1(10,-6,6);
	v3d v2(10,3,0);

	Triangle tr(v0,v1,v2);

	std::vector<tObject*> obj;

	obj.push_back(&s6);
	obj.push_back(&s1);
	obj.push_back(&rect);
	obj.push_back(&r2);
	obj.push_back(&r3);
	obj.push_back(&r4);
	obj.push_back(&r5);
	obj.push_back(&r7);
	obj.push_back(&backboard);

	// obj.push_back(&tr);

	srand(69);


/*
	//testing bvh

	Sphere *hi[690000];
	for (int i=0;i<50000;i++) {
		hi[i] = new Sphere(tUtility::rand_range(-10000,5),tUtility::rand_range(-10000,100),tUtility::rand_range(-1000,100),15);
		hi[i]->set_material(perfect);
		obj.push_back(hi[i]);
	}
/*
*/
	tr.set_material(red2);

	backboard.set_material(diffuse);
	s1.set_material(diffuse);
	s6.set_material(perfect);
	rect.set_material(diffuse);
	r2.set_material(diffuse);
	r3.set_material(diffuse);
	r4.set_material(green);
	r5.set_material(red);
	r7.set_material(light);
	rect.set_viewport(pix(1,0,0));
	r2.set_viewport(pix(0,1,0));
	r3.set_viewport(pix(0,0,1));
	r4.set_viewport(pix(.5,.5,0));
	r5.set_viewport(pix(0,.5,.5));
	
	tr.set_viewport(pix(1,.5,0));

	shiniee.set_emission(pix(0,0,0));
	Scene sc(cam,obj);

	sc.render();
	// sc.single_pass();

	for (tObject* o : obj) {
		v3d min,max;
		o->minmax_points(min,max);
		// std::cout << "minmax: " << min << " " << max << "\n";
	}
	// std::cout << cr << "\n";
	// std::cout << cam << "\n";
	// r.intersect(s);
}