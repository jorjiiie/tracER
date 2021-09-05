#include "Scene.cpp"
#include "SceneIO.cpp"

#define STEPS 100
int main() {

	std::string f = "bunny4.txt";

	// we have to find the center of the bunny, then direction is just center - camera position
	for (int i=0;i<STEPS;i++) {
		v3d center(-5,-10,0);

		

		v3d up(0,-1,0);

		// ceneter around -7, 10 or something
		double angle = 2*PI/STEPS * i;
		double radius = 20;
		v3d origin(-7 + radius*sin(angle),-10,radius*cos(angle));


		v3d direction = (center - origin).normalize();
		Camera cam(400,300,origin,up,direction,110,0,69);

		std::vector<tObject*> obj;
		Sphere s6(-7,-55,0,15);
		Sphere s1(-7,25,0,12);
		obj.push_back(&s1);
		obj.push_back(&s6);
		s6.set_viewport(pix(1,1,1));

		Lambertian jj(pix(1,1,1));
		jj.set_emission(pix(30,30,30));
		s6.set_material(jj);
		s1.set_material(jj);


		// Lambertian cool(pix(.6,.6,.6));
		// Rectangle flor(-20,20,-20,20,-10,2);
		// obj.push_baclsk(&flor);
		// flor.set_material(jj);

		Scene sc(cam,obj);
		ply_to_scene(sc,f);
		sc.name_output(std::to_string(i));
		sc.render();
		// std::cout << sc.scene_objects.size() << "\n";
	}
}