#pragma once

#include "Metal.h"


Metal::Metal(const pix& a, double fac) {
	albedo = a;
	roughness = fac;
}

void Metal::get_scatter(const Ray& r, const v3d& normal, const v3d& p, Ray& outgoing) {
	// instead of random direction, we do a sick reflection with maybe fuzz?

	// given ||v|| = ||u|| = 1
	// v proj u  = u *  (v • u)

	// reflection is r.d - 2*r.d P n

	v3d new_direction = r.direction - normal * (normal * r.direction  * 2.0);

	if (roughness > .001) {
		new_direction += tUtility::uniform_sphere() * roughness;
	}
	Ray ret(p, new_direction);

	outgoing = ret;


}
