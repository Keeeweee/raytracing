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

	inline float schlick(float cosine) const
	{
		float r0 = (1. - this->refIndex) / (1 + this->refIndex);
		r0 = r0 * r0;
		return r0 + (1. - r0) * pow(1 - cosine, 5);
	}

	bool scatter(const Ray& ray, const hitRecord& hit, Vec3& attenuation, Ray& scattered) const override {
		Vec3 outwardNormal{};

		float niOverNt;
		attenuation = Vec3(1.0, 1.0, 1.0);
		Vec3 refracted{};
		float reflectProb;
		float cosine;
		if (dot(ray.direction, hit.normal) > 0)
		{
			outwardNormal = -hit.normal;
			niOverNt = this->refIndex;
			cosine = this->refIndex * dot(ray.direction, hit.normal) / ray.direction.length();
		}
		else
		{
			outwardNormal = hit.normal;
			niOverNt = 1. / this->refIndex;
			cosine = -dot(ray.direction, hit.normal) / ray.direction.length();
		}

		if (refract(ray.direction, outwardNormal, niOverNt, refracted))
		{
			reflectProb = schlick(cosine);
		}
		else
		{
			reflectProb = 1.;
		}

		if (random() < reflectProb)
		{
			scattered = Ray(hit.p, reflect(ray.direction, hit.normal));
		}
		else
		{
			scattered = Ray(hit.p, refracted);
		}

		return true;
	}
};

