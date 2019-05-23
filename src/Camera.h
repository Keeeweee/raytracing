#pragma once

#include "Ray.h"
#include <cmath>

class Camera
{
public:
	Vec3 origin{};
	Vec3 lowerLeftCorner{};
	Vec3 horizontal{};
	Vec3 vertical{};

	Camera(float vFov, float aspect)
	{
		float theta = vFov * 3.14159265358979 / 180;
		float halfHeight = std::tan(theta / 2.);
		float halfWidth = aspect * halfHeight;

		this->lowerLeftCorner = Vec3(-halfWidth, -halfHeight, -1.);
		this->horizontal = Vec3(2 * halfWidth, 0., 0.);
		this->vertical = Vec3(0., 2. * halfHeight, 0.);
		this->origin = Vec3(0., 0., 0.);
	}

	Ray getRay(float u, float v)
	{
		return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
	}
};