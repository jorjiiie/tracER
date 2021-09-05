#pragma once

#include "Lambertian.h"

Lambertian::Lambertian(const pix& a) {
	albedo = a;
}

void Lambertian::get_scatter(const Ray& r, const v3d& normal, const v3d& p, Ray& return_ray) {

	// random sphere thing?
	v3d rand = tUtility::uniform_sphere().normalize();

	v3d direction = rand + normal;

	Ray ret(p,direction);
	return_ray = ret;
}

