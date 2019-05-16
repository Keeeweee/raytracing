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

	inline Color getBlueGradient()
	{
		float t = 0.5 * this->direction.y() + 1.0;
		float inverseT = 1. - t;
		return Color(inverseT + t * 0.5, inverseT + t * 0.7, inverseT + t);
	}

	Color getColor(Shape &world)
	{
		hitRecord hit;
		if (world.hit(*this, 0.0, FLT_MAX, hit))
		{
			return Color(0.5 * (hit.normal.x() + 1.), 0.5 * (hit.normal.y() + 1.), 0.5 * (hit.normal.z() + 1.));
		}

		return getBlueGradient();
	}
};

