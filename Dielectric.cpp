#pragma once

#include "Dielectric.h"


Dielectric::Dielectric(const pix&, double ior) {
	albedo = a;
	this-> ior = ior;
}

void Dielectric::get_scatter(const Ray& inc, const v3d& normal, const v3d& point, Ray& outgoing) {
	double r = 1/
}