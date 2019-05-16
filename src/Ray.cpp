//
// Created by dev on 16/05/2019.
//

#include "Ray.h"

Ray::Ray() = default;

Ray::Ray(const Vec3 &a, const Vec3 &b)
{
	this->origin = a;
	this->direction = Vec3::unitVector(b);
}

Vec3 Ray::pointAtParameter(float t) const
{
	return this->origin + t * direction;
}

Color Ray::getColor()
{
	float t = 0.5 * this->direction.y() + 1.0;
	float inverseT = 1. - t;
	return Color(inverseT + t * 0.5, inverseT + t * 0.7, inverseT + t);
}
