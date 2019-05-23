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
};

