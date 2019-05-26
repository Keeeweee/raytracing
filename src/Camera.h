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
	Vec3 u, v, w;
	float lensRadius;

	Camera(Vec3 lookFrom, Vec3 lookAt, Vec3 vUp, float vFov, float aspect, float aperture, float focusDistance)
	{
		this->lensRadius = aperture / 2.;
		float theta = vFov * 3.14159265358979 / 180;
		float halfHeight = std::tan(theta / 2.);
		float halfWidth = aspect * halfHeight;

		this->origin = lookFrom;
		this->w = Vec3::unitVector(lookFrom - lookAt);
		this->u = Vec3::unitVector(cross(vUp, w));
		this->v = cross(w, u);

		this->lowerLeftCorner = this->origin - focusDistance * (halfWidth * u + halfHeight * v + w);

		this->horizontal = 2. * focusDistance * halfWidth * u;
		this->vertical = 2. * focusDistance * halfHeight * v;
	}

	Ray getRay(float s, float t)
	{
		Vec3 rd = this->lensRadius * utils::randomInUnitDisk();
		Vec3 offset = this->u * rd.x() + this->v * rd.y();
		return Ray( this->origin + offset,
					this->lowerLeftCorner + s * this->horizontal + t * this->vertical - this->origin - offset);
	}
};