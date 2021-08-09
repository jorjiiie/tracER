#pragma once
#include "Material.h"

Material::Material() {

}

Material::Material(const pix& a) {
	albedo = a;
}
Material::Material(const pix& a, const pix& e) {
	albedo = a;
	emission = e;
}
void Material::set_emission(const pix& e) {
	emission = e;
}
void Material::get_scatter(const Ray&, const v3d&, const v3d&, Ray&) {
	return;
}