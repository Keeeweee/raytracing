#pragma once

#include "Material.h"

class Lambertian: public Material
{
public:
	Vec3 albedo{};
	explicit Lambertian(const Vec3& albedo)
	{
		this->albedo = albedo;
	}

	bool scatter(const Ray& ray, const hitRecord& hit, Vec3& attenuation, Ray& scattered) const override {
		(void)ray;
		Vec3 target = hit.p + hit.normal + utils::randomInUnitSphere();
		scattered = Ray(hit.p, target - hit.p);
		attenuation = this->albedo;
		return true;
	}
};