#pragma once

#include "Material.cpp"

class Metal : public Material {
	// should call this glossy
public:
	Metal(const pix&, double);
	virtual void get_scatter(const Ray&, const v3d&, const v3d&, Ray&);

private:
	double roughness;
};