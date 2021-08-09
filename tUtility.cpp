#pragma once
#include <iostream>
#include <fstream>

#include "v3d.h"
#include "pix.h"

namespace tUtility {
	v3d uniform_sphere() {
		v3d direction;
		
		do {
			direction.x = (double) rand() / RAND_MAX * 2 - 1;
			direction.y = (double) rand() / RAND_MAX * 2 - 1;
			direction.z = (double) rand() / RAND_MAX * 2 - 1;

			// while magnitude < 1
		} while (direction * direction < 1);
		return direction;
	}
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

}