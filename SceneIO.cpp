#pragma once

#include <fstream>
#include <iostream>


#include "Scene.cpp"


void ply_to_scene(Scene& s, std::string name) {
	std::ifstream in(name);


	if (in) {
		std::cout << "file uwu\n";
		int n,m;
		in >> n >> m;
		std::vector<v3d> points(n);
		double mx=0,mn=69;
		for (int i=0;i<n;i++) {
			v3d joe;
			for (int j=0;j<m;j++) {
				// just take the first 3 bc uwu
				double k;
				in >> k;
				k*=100;
				if (j<3) {
					if (j==0)
						joe.x= k;
					else if (j==1)
						joe.y = -k;
					else joe.z=k;

					mx = std::max(mx, k);
					mn = std::min(mn, k);

				}
			}
			points[i]=joe;
		}


		int faces;
		in >> faces;

		Lambertian *uwu = new Lambertian(pix(.5,.5,.5));
		// uwu->set_emission(pix(.2,.2,.2));
		Lambertian owo(pix(.5,.5,.5));
		for (int i=0;i<faces;i++) {
			int waste;
			in >> waste;
			int a,b,c;
			in >> a >> b >> c;
			Triangle * joe = new Triangle(points[a],points[b],points[c]);
			joe->set_viewport(pix(1,1,1));
			joe->set_material(uwu);
			// std::cout << points[a] << " " << points[b] << " " << points[c] << "\n";
			s.add_obj(joe);
		}
	} else {
		std::cout << "File couldn't be opened\n";
		return;
	}
}