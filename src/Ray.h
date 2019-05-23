#pragma once

#include <cmath>
#include <cfloat>

#include "Vec3.h"
#include "Color.h"
#include "Utils.h"
#include "shapes/Shape.h"
#include "materials/Material.h"

class Ray
{
public:
	Vec3 origin{};
	Vec3 direction{};

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

	inline Vec3 getBlueGradient()
	{
		float t = 0.5 * this->direction.y() + 1.0;
		float inverseT = 1. - t;
		return Vec3(inverseT + t * 0.5, inverseT + t * 0.7, inverseT + t);
	}

	Vec3 getColor(Shape &world, int depth)
	{
		hitRecord hit{};
		if (world.hit(*this, 0.001, FLT_MAX, hit))
		{
			Ray scattered;
			Vec3 attenuation;
			if (depth < 50 && hit.materialPtr->scatter(*this, hit, attenuation, scattered))
			{
				return attenuation * scattered.getColor(world, depth+1);
			}
			else
			{
				return Vec3(0., 0., 0.);
			}
		}

		return getBlueGradient();
	}
};

