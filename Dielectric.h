#pragma once

#include "Material.cpp"

class Dielectric : public Material {
	// diffuse
public:
	Dielectric(const pix&,double);
	virtual void get_scatter(const Ray&, const v3d&, const v3d&, Ray&);

	// if we wanted to do this properly we would carry ior of material before hitting
	//but it's always air? LOL	
	double ior;
};