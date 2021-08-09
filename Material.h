#pragma once

#include "Ray.cpp"
#include "v3d.h"
#include "tUtility.cpp"

class Material {
public:
	Material();
	Material(const pix&);
	Material(const pix&, const pix&);
	void set_emission(const pix&);
	// i have no clue :(
	// incoming, normal, point?
	virtual void get_scatter(const Ray&, const v3d&, const v3d&, Ray&);
protected:
	// good design? no
	friend class Scene;

	pix emission;
	pix albedo;


};