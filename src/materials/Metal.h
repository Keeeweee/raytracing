#pragma once

#include "Material.h"


class Metal : public Material
{
public:
	Vec3 albedo{};
	explicit Metal(const Vec3& albedo)
	{
		this->albedo = albedo;
	}

	bool scatter(const Ray& ray, const hitRecord& hit, Vec3& attenuation, Ray& scattered) const override {
		Vec3 reflected = reflect(ray.direction, hit.normal);
		scattered = Ray(hit.p, reflected);
		attenuation = this->albedo;
		return (dot(scattered.direction, hit.normal) > 0);
	}
};

