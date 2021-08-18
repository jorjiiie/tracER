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

// multithreaded 
void Scene::render_main(std::vector<std::vector<v3d> >& points, std::vector<std::vector<pix> >& img, std::vector<std::vector<int> >& rendered, v3d& d_pix, v3d& d_up, int t_id, std::vector<int>& completed, int thread_count) {
	// this will be weird lol but its fine
	clock_t start = clock();
	int pixels = cam.width*cam.height;
	for (int i=0;i<cam.height;i++) {
		for (int j=0;j<cam.width;j++) {
			// can probably set this to the threadid
			// manual mutex :D
			if (rendered[j][i]!=0) continue;
			rendered[j][i] = t_id;

			
			v3d ray_base = points[j][i] - cam.position;

			// we do some math to make sure another competing thread can actually get the lock
			// so if this is true, this will continue and the competing thread will get this pixel
			// pray its good enough LOL
			if (rendered[j][i]!=t_id) continue;
			for (int k = 0; k < SAMPLES; k++) {

				v3d ray_vec = points[j][i] - cam.position + d_pix * tUtility::rand_range(-1,1) + d_up * tUtility::rand_range(-1,1);
				ray_vec.normalize();

				v3d offset(0,0,0);
				v3d ray_origin = cam.position;
				if (cam.apeture>0.01) {
					do {
						offset.x = tUtility::random();
						offset.y = tUtility::random();
					}
					while (offset*offset > 1);
					offset *= cam.apeture;
					ray_origin += d_up * offset.x + d_pix * offset.y;
				}

				Ray current(ray_origin,ray_vec);

				img[j][i] += trace(current, MAX_BOUNCES);
			}
		}
		completed[i]++;
		if (completed[i] == thread_count) {
			int current = cam.width*(i+1);
			double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC / thread_count;
			if (!DEBUG_MODE) fprintf(stdout,"\r%d/%d pixels rendered at %d samples (%1.0f%%) Elapsed time is %.1f seconds, estimated %.1f seconds left",current,pixels,SAMPLES, (double)current/pixels*100, elapsed, elapsed*pixels/current - elapsed);
			else fprintf(stdout, "\r%dx%d@%d %d%% %.1f %.1f ",cam.width,cam.height,SAMPLES,(int)(current *100.0/ pixels), elapsed, elapsed*pixels/current - elapsed);
			fflush(stdout);
		}	
	}
}

void Scene::render() {

	// see render() for details

	std::vector<std::vector<pix> > img(cam.width);
	for (std::vector<pix>& v : img) {
		v.resize(cam.height);
	}
	std::vector<std::vector<v3d> > points(cam.width);
	for (std::vector<v3d>& v : points) {
		v.resize(cam.height);
	}

	// scaled to focus distance
	v3d center_scene = cam.position + cam.direction * cam.focus;

	v3d d_pix = cam.direction.cross(cam.up);
	v3d d_up = cam.up;
	d_pix.normalize();

	double width = tan(cam.angle * PI/360.0) * cam.focus * 2;

	d_pix *= width / (cam.width-1);
	d_up *= width / (cam.width-1);

	v3d lower_left = center_scene - (d_pix * (cam.width/2)) - (d_up * (cam.height/2));
	
	points[0][cam.height-1]=lower_left;

	for (int i = 1; i < cam.width; i++) {
		points[i][cam.height-1] = points[i-1][cam.height-1] + d_pix;
	}

	for (int i = cam.height-2; i >= 0; i--) {

		points[0][i] = points[0][i+1] + d_up;

		for (int j = 1; j < cam.width; j++) {
			points[j][i] = points[j-1][i] + d_pix;
		}
	}
	// locks
	// hopefully it works
	std::vector<std::vector<int> > rendered(cam.width);
	for (std::vector<int>& vec : rendered) {
		vec.resize(cam.height);
	}
	// get time estimate
	std::vector<int> completed(cam.height);

	int thread_max = std::max((int)std::thread::hardware_concurrency(),1);
	std::vector<std::thread> threads;

	clock_t start = clock();

	// thread_max = 1;
	for (int i=0;i<thread_max;i++) {
		threads.push_back(std::thread(&Scene::render_main,this,std::ref(points),std::ref(img),std::ref(rendered),std::ref(d_pix),std::ref(d_up),i+1,std::ref(completed),thread_max));
	}
	for (auto& t1 : threads) {
		t1.join();
	}
	std::ofstream out;
	out.open("output/test34.ppm");
	out << "P3 " << cam.width << " " << cam.height << " 255\n";

	for (int i=0;i<cam.height;i++)
		for (int j=0;j<cam.width;j++) {
			img[j][i].gamma_correct(SAMPLES);
			tUtility::print_color(out,img[j][i]);
		}

}
