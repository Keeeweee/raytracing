#pragma once


#include "Material.h"

class Dielectric : public Material
{
public:
	float refIndex;
	explicit Dielectric(float refIndex)
	{
		this->refIndex = refIndex;
	}

	bool scatter(const Ray& ray, const hitRecord& hit, Vec3& attenuation, Ray& scattered) const override {
		Vec3 outwardNormal{};
		Vec3 reflected = reflect(ray.direction, hit.normal);

		float niOverNt;
		attenuation = Vec3(1.0, 1.0, 1.0);
		Vec3 refracted{};
		if (dot(ray.direction, hit.normal) > 0)
		{
			outwardNormal = -hit.normal;
			niOverNt = this->refIndex;
		}
		else
		{
			outwardNormal = hit.normal;
			niOverNt = 1. / this->refIndex;
		}

		if (refract(ray.direction, outwardNormal, niOverNt, refracted))
		{
			scattered = Ray(hit.p, refracted);
		}
		else
		{
			scattered= Ray(hit.p, reflected);
		}
		return true;
	}
};

