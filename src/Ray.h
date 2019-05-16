#pragma once

#include "Vec3.h"
#include "Color.h"

class Ray
{
public:
	Vec3 origin;
	Vec3 direction;

	Ray() = default;

	Ray(const Vec3 &a, const Vec3 &b)
	{
		this->origin = a;
		this->direction = Vec3::unitVector(b);
	}

	inline Vec3 pointAtParameter(float t) const
	{
		return this->origin + t * direction;
	}

	Color getColor()
	{
		if (hitSphere(Vec3(0., 0., -1.), 0.5))
		{
			return Color(1., 0., 0.);
		}

		return getBlueGradient();
	}

private:
	inline bool hitSphere(const Vec3& center, float radius)
	{
		Vec3 oc = this->origin - center;
		float a = dot(this->direction, this->direction);
		float b = 2. * dot(oc, this->direction);
		float c = dot(oc, oc) - radius * radius;
		float discriminant = b * b - 4 * a * c;

		return (discriminant > 0);
	}

	inline Color getBlueGradient()
	{
		float t = 0.5 * this->direction.y() + 1.0;
		float inverseT = 1. - t;
		return Color(inverseT + t * 0.5, inverseT + t * 0.7, inverseT + t);
	}
};

