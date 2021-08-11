#pragma once
#include "Scene.h"

Scene::Scene() {
	// hello
}

Scene::Scene(Camera c, std::vector<tObject*> objs) {
	cam = c;
	scene_objects = objs;
}

pix Scene::trace(const Ray r, int depth) {

	if (depth <= 0) 
		return pix(0,0,0);

	// default to diffuse for now
	tObject* hit = NULL;

	double min_dist = 6942000.0;
	for (tObject* o : scene_objects) {
		double t;
		if (o->intersect(r,t)) {
			if (t < min_dist) {
				hit = o;
				min_dist = t;
			}
		}
	}

	pix col;
	// no hit or clip
	if (hit == NULL || std::abs(min_dist) < .000001) {
		// add world color
		// whyte		
		return pix(0,0,0);
	} else {
		
		// point of intersection
		v3d point = r.position + r.direction * min_dist;

		Material* mat = hit->get_material();

		v3d normal = hit->get_normal(point);

		Ray new_ray;
		mat->get_scatter(r,normal,point,new_ray);

		// emission + attenuation * (incoming)
		col +=  mat->emission + mat->albedo * trace(new_ray, depth-1);
	}
	return col;
}

void Scene::render() {

	// both of these should be switched but i can't be bothered now
	// cache friendly would be other way aroudn LOL but its fine for now
	// we get to do some testing later
	std::vector<pix> img[cam.width];
	for (std::vector<pix>& v : img) {
		v.resize(cam.height);
	}

	// projected big triangle points
	std::vector<v3d> points[cam.width];
	for (std::vector<v3d>& v : points) {
		v.resize(cam.height);
	}
	// now project a big rectangle through camera and shoot rays through the pixels

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
	d_pix.normalize();



	// length of the entire thing = tan(angle/2) * distance to center
	// just draw the triangle, this is the bisecting the iscoelenes one

	// converting to radians :(((
	double width = tan(cam.angle * PI/360.0) * 69 * 2;

	// now scale d_pix and d_up (one pixel is width/(cam.width-1)^2 units)
	d_pix *= width / (cam.width-1);
	d_up *= width / (cam.width-1);

	// now we go to the low, left thing
	v3d lower_left = center_scene - (d_pix * (cam.width/2)) - (d_up * (cam.height/2));
	
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

	// for (int i=0;i<cam.height;i++) {
	// 	for (int j=0;j<cam.width;j++) {
	// 		std::cerr << points[j][i] << ", ";
	// 	}
	// 	std::cerr << "\n";
	// }

	// should flip samples first for progressive sampling for non speed but look at difference
	int pixels = cam.width * cam.height;
	int current = 0;
	// std::cout << current << "/" << pixels << " rendered at " << SAMPLES << " samples"; 
	clock_t start = clock();
	fprintf(stdout,"%d/%d rendered at %d samples. ",current,pixels,SAMPLES);
	for (int i=0;i<cam.height;i++) {
		for (int j=0;j<cam.width;j++) {
			for (int k = 0; k < SAMPLES; k++) {
				// add random variation within pixel
				v3d ray_vec = points[j][i] - cam.position + d_pix * (rand() * 1.0 / RAND_MAX * 2 - 1) + d_up * (rand() * 1.0 / RAND_MAX * 2 - 1);
				ray_vec.normalize();
				Ray current(cam.position,ray_vec);

				img[j][i] += trace(current, MAX_BOUNCES);

			}
			current++;
		}
		double elapsed = (double) (clock() - start) / CLOCKS_PER_SEC;
		fprintf(stdout,"\r%d/%d pixels rendered at %d samples (%1.0f%%) Elapsed time is %.1f seconds, estimated %.1f seconds left",current,pixels,SAMPLES, (double)current/pixels*100, elapsed, elapsed*pixels/current - elapsed);
		std::fflush(stdout);
		// std::cout << "\033[2K\r" << current << "/" << pixels << " rendered at " << SAMPLES << " samples"; 
			// std::cerr << "[" << img[i][j].r << " " << img[i][j].g << " " << img[i][j].b << "] ";
			// img[i][j]/=SAMPLES;
		
		// std::cerr << "\n";
	
	}
	std::cout << "\n";
	// output to file & image initialization
	std::ofstream out;
	out.open("output/test33.ppm");
	out << "P3 " << cam.width << " " << cam.height << " 255\n";

	for (int i=0;i<cam.height;i++)
		for (int j=0;j<cam.width;j++) {
			img[j][i].gamma_correct(SAMPLES);
			tUtility::print_color(out,img[j][i]);
		}

}