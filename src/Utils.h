#pragma once

#include <random>
#include <cmath>

namespace utils
{
	inline float random()
	{
		static std::random_device rd;
		static std::mt19937 e2(rd());
		static std::uniform_real_distribution<> dist(0, 1);

		return dist(e2);
	}

	inline Vec3 randomInUnitSphere()
	{
		Vec3 p{};

		do
		{
			p = 2.0 * Vec3(utils::random(), utils::random(), utils::random()) - Vec3(1., 1., 1.);
		} while (p.squaredLength() >= 1.);

		return p;
	}

	inline Vec3 randomInUnitDisk()
	{
		Vec3 p{};

		do
		{
			p = 2.0 * Vec3(utils::random(), utils::random(), 0.) - Vec3(1., 1., 0.);
		} while (p.squaredLength() >= 1.);

		return p;
	}
}