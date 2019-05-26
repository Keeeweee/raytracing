#pragma once

#include "Material.h"


class Metal : public Material
{
public:
	Vec3 albedo{};
	float fuzz;
	explicit Metal(const Vec3& albedo, float fuzz)
	{
		this->albedo = albedo;

		this->fuzz = fuzz < 1. ? fuzz : 1.;
	}

	bool scatter(const Ray& ray, const hitRecord& hit, Vec3& attenuation, Ray& scattered) const override {
		Vec3 reflected = reflect(ray.direction, hit.normal);
		scattered = Ray(hit.p, reflected + fuzz * utils::randomInUnitSphere());
		attenuation = this->albedo;
		return (dot(scattered.direction, hit.normal) > 0);
	}
};

