#pragma once

#include "Shape.h"

class Sphere: public Shape
{
public:
	Vec3 center{};
	float radius{};
	Material* materialPtr;

	Sphere() = default;

	Sphere(Vec3 center, float radius, Material* materialPtr)
	{
		this->center = center;
		this->radius = radius;
		this->materialPtr = materialPtr;
	}

	bool hit(const Ray& ray, float tMin, float tMax, hitRecord& hit) const override
	{
		Vec3 oc = ray.origin - center;
		float a = dot(ray.direction, ray.direction);
		float b = dot(oc, ray.direction);
		float c = dot(oc, oc) - radius * radius;

		float discriminant = b * b + a * c;

		if (discriminant > 0)
		{
			float temp = (-b - std::sqrt(b * b - a * c)) / a;
			if (temp < tMax and temp > tMin)
			{
				hit.t = temp;
				hit.p = ray.pointAtParameter(temp);
				hit.normal = (hit.p - center) / radius;
				hit.materialPtr = materialPtr;
				return true;
			}

			temp = (-b + std::sqrt(b * b - a * c)) / a;
			if (temp < tMax and temp > tMin)
			{
				hit.t = temp;
				hit.p = ray.pointAtParameter(temp);
				hit.normal = (hit.p - center) / radius;
				hit.materialPtr = materialPtr;
				return true;
			}
		}
		return false;
	}
};

