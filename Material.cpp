#pragma once
#include "Material.h"

Material::Material() {

}

Material::Material(const pix& a) {
	albedo = a;
}
void Material::get_scatter(const Ray&, const v3d&, const v3d&, Ray&) {
	return;
}