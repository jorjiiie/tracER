#pragma once
#include "Scene.h"


Scene::Scene() {
	// hello
}
Scene::Scene(Camera c, std::vector<tObject*> objs) {
	cam = c;
	scene_objects = objs;

}
void Scene::render() {

	// output to file & image initialization
	std::ofstream out;
	out.open("output/test.ppm");
	out << "P3 " << cam.width << " " << cam.height << " 255\n";

	pix img[cam.width+2][cam.height+2];


	memset(img,0,sizeof(img));

	// now project a big rectangle through camera and shoot rays through the pixels
	// will have multiple samples per pixel eventually but for now...
	// single shot straight through <3

	// center of the scene, and is 69 units away from the camera for no reason whatsoever
	// it doesn't make a difference bc the ray intersection doesn't matter for magnitude
	// will just have bigger numbers :c
	v3d center_scene = cam.position + cam.direction * 69;

	// delta x,y,z per pixel sideways
	// for a pixel, moving right 1 pix is + d_pix
	// moving up 1 pix is + d_up

	// we live in a right hand priviledged society
	v3d d_pix = cam.direction.cross(cam.up);
	v3d d_up = cam.up;
	d_pix.to_unit();


	// length of the entire thing = tan(angle/2) * distance to center
	// just draw the triangle, this is the bisecting the iscoelenes one

	// converting to radians :(((
	double width = tan(cam.angle * PI/360.0) * 69 * 2;

	// now scale d_pix and d_up (one pixel is width/(cam.width-1)^2 units)
	d_pix *= width / (cam.width-1);
	d_up *= width / (cam.width-1);

	// now we go to the low, left thing
	v3d lower_left = center_scene - (d_pix * (cam.width/2)) - (d_up * (cam.height/2));


	v3d points[cam.width][cam.height];
	
	points[0][cam.height-1]=lower_left;



	// fill in bottom row
	for (int i = 1; i < cam.width; i++) {
		points[i][cam.height-1] = points[i-1][cam.height-1] + d_pix;
	}


	for (int i = cam.height-2; i >= 0; i--) {

		points[0][i] = points[0][i+1] + d_up;

		for (int j = 1; j < cam.width; j++) {
			points[j][i] = points[j-1][i] + d_pix;
		}
	}


	
	// debugging
	/*
	std::cerr << d_pix << " " << d_up << " " << width << " " << lower_left;
	std::cerr << "\n";
	for (int i=0;i<cam.height;i++) {
		std::cerr << "ROW " << i << ": ";
		for (int j=0;j<cam.width;j++) {
			v3d tmp = points[j][i];
			std::cerr << tmp<< " ";
		}
		std::cerr << "\n";
	}
	//*/
	for (int i=0;i<cam.width;i++) {
		for (int j=0;j<cam.height;j++) {
			for (int k = 0; k < SAMPLES; k++) {
				v3d ray_vec = points[j][i] - cam.position + d_pix * (rand() * 1.0 / RAND_MAX * 2 - 1) + d_up * (rand() * 1.0 / RAND_MAX * 2 - 1);
				ray_vec.to_unit();
				Ray current(cam.position,ray_vec);
				for (tObject* o : scene_objects) {
					// since its reference it wont slice it pray
					// it slices :(
					Sphere* tmp_s = static_cast<Sphere*>(o);
					if (current.intersect(*tmp_s)) {
						img[i][j].r+=255;
						img[i][j].g+=255;
						img[i][j].b+=255;
					}
				}
			}
			img[i][j].r /= SAMPLES;
			img[i][j].g /= SAMPLES;
			img[i][j].b /= SAMPLES;
		}
	}

	for (int i=0;i<cam.height;i++)
		for (int j=0;j<cam.width;j++)
			out << img[j][i].r << " " << img[j][i].g << " " << img[j][i].b << "\n";


}