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

	Camera(Vec3 lookFrom, Vec3 lookAt, Vec3 vUp, float vFov, float aspect)
	{
		Vec3 u{}, v{}, w{};
		float theta = vFov * 3.14159265358979 / 180;
		float halfHeight = std::tan(theta / 2.);
		float halfWidth = aspect * halfHeight;

		this->origin = lookFrom;
		w = Vec3::unitVector(lookFrom - lookAt);
		u = Vec3::unitVector(cross(vUp, w));
		v = cross(w, u);

		this->lowerLeftCorner = this->origin - halfWidth * u - halfHeight * v - w;

		this->horizontal = 2. * halfWidth * u;
		this->vertical = 2. * halfHeight * v;
	}

	Ray getRay(float u, float v)
	{
		return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - this->origin);
	}
};