#pragma once

#include "Ray.h"

class Camera
{
public:
	Vec3 origin{};
	Vec3 lowerLeftCorner{};
	Vec3 horizontal{};
	Vec3 vertical{};

	Camera()
	{
		this->lowerLeftCorner = Vec3(-2., -1., -1.);
		this->horizontal = Vec3(4., 0., 0.);
		this->vertical = Vec3(0., 2., 0.);
		this->origin = Vec3(0., 0., 0.);
	}

	Ray getRay(float u, float v)
	{
		return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
	}
};