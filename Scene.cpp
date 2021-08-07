#pragma once
#include "Scene.h"


Scene::Scene() {
	// hello
}

Scene::Scene(Camera c, std::vector<tObject*> objs) {
	cam = c;
	scene_objects = objs;
}

v3d Scene::uniform_hemisphere(const v3d& loc, const v3d& normal, const v3d& center) {
	// we do this by literally guessing LOL
	v3d direction;
	// so uh we just take 3 random points and check if its in the unit sphere
	// this is uniform LOL bc its in the sphere and each 'radius' has equal probablity
	// the probablity of ray being in the sphere is pi/6 or a bit higher than 50%
	// soooo theoretically it should be 4 or less iterations 95% of the time :) 

	// apparently this is commonly used and is just a 'rejection testing'
	do {
		direction.x = (double) rand() / RAND_MAX * 2 - 1;
		direction.y = (double) rand() / RAND_MAX * 2 - 1;
		// only want up
		// if doing transmission then we can just flip this 
		direction.z = (double) rand() / RAND_MAX;


		// while magnitude < 1
	} while (direction * direction < 1);

	// direction is now on the +z hemisphere
	// align to the normal point
	// really just need the normal?

	// calculate rotation matrix here	

	// LOL NOPE
	// just return this for now LMFAO 
	return direction;
}

v3d Scene::uniform_sphere() {
	v3d direction;
	
	do {
		direction.x = (double) rand() / RAND_MAX * 2 - 1;
		direction.y = (double) rand() / RAND_MAX * 2 - 1;
		direction.z = (double) rand() / RAND_MAX * 2 - 1;

		// while magnitude < 1
	} while (direction * direction < 1);
	return direction;
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
	if (hit == NULL) {
		// add world color
		// whyte		
		return pix(1,1,1);
	} else {
		
		v3d point = r.position + r.direction * min_dist;

		// assume it's a sphere so
		v3d normal = hit->get_normal(point);

		v3d sphere_point = normal + uniform_sphere();

		Ray new_ray(point,sphere_point);

		// maybe have to convert to double and print the int 
		col+= trace(new_ray, depth-1) * .5;
	}
	return col;
}

// some funcs LOL
// spaghetti code crying :(
double clamp(double a, double mn, double mx) {
	if (a<mn) return mn;
	if (a>mx) return mx;
	return a;
}
void print_color(std::ofstream& out, pix pixel) {
	out << (int) (256 * clamp(pixel.r,0.0,0.9999)) << " " 
		<< (int) (clamp(pixel.g,0.0,0.9999) * 256) << " " 
		<< (int) (clamp(pixel.b,0.0,0.9999) * 256) << "\n";
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


	// should flip samples first for progressive sampling for non speed but look at difference
	for (int i=0;i<cam.width;i++) {
		for (int j=0;j<cam.height;j++) {
			for (int k = 0; k < SAMPLES; k++) {
				// add random variation within pixel
				v3d ray_vec = points[j][i] - cam.position + d_pix * (rand() * 1.0 / RAND_MAX * 2 - 1) + d_up * (rand() * 1.0 / RAND_MAX * 2 - 1);
				ray_vec.normalize();
				Ray current(cam.position,ray_vec);

				img[i][j] += trace(current, 3);

			}
			// std::cerr << "[" << img[i][j].r << " " << img[i][j].g << " " << img[i][j].b << "] ";
			// img[i][j]/=SAMPLES;
		}
		// std::cerr << "\n";
	}
	// output to file & image initialization
	std::ofstream out;
	out.open("output/test3.ppm");
	out << "P3 " << cam.width << " " << cam.height << " 255\n";

	for (int i=0;i<cam.height;i++)
		for (int j=0;j<cam.width;j++) {
			img[j][i].gamma_correct(SAMPLES);
			print_color(out,img[j][i]);
		}

}