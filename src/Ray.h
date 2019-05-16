#pragma once

#include "Vec3.h"
#include "Color.h"

class Ray
{
public:
	Vec3 origin;
	Vec3 direction;

	Ray();
	Ray(const Vec3& a, const Vec3& b);

	Vec3 pointAtParameter(float t) const;

	Color getColor();
};