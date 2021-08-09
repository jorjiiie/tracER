#pragma once

#include "Material.cpp"

class Lambertian : public Material {
	// diffuse
public:
	Lambertian(const pix&);
	virtual void get_scatter(const Ray&, const v3d&, const v3d&, Ray&);

};