#pragma once


#include "../Vec3.h"

class Ray;
class Material;

struct hitRecord
{
	float t;
	Vec3 p;
	Vec3 normal;
	Material *materialPtr;
};

class Shape
{
public:
	virtual bool hit(const Ray& ray, float tMin, float tMax, hitRecord& hit) const = 0;

};
