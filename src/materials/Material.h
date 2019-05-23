#include <cmath>

#pragma once


#include "../Ray.h"

class Material
{
public:
	virtual bool scatter(const Ray& ray, const hitRecord& hit, Vec3& attenuation, Ray& scattered) const = 0;

	static inline Vec3 reflect(const Vec3& v, const Vec3& n)
	{
		return v - 2. * dot(v, n) * n;
	}

	static inline bool refract(const Vec3& v, const Vec3& n, float niOverNt, Vec3& refracted)
	{
		Vec3 uv = Vec3::unitVector(v);
		float dt = dot(uv, n);
		float discriminant = 1. - niOverNt * niOverNt * (1. - dt * dt);

		if (discriminant > 0)
		{
			refracted = niOverNt * (uv - n * dt) - n * std::sqrt(discriminant);
			return true;
		}

		return false;
	}
};

