#include <cmath>

#include "Vec3.h"

#include <iostream>
#include <cmath>

Vec3::Vec3() = default;

Vec3::Vec3(float e0, float e1, float e2)
{
	e[0] = e0;
	e[1] = e1;
	e[2] = e2;
}

inline float Vec3::x()
{
	return e[0];
}

inline float Vec3::y()
{
	return e[1];
}

inline float Vec3::z()
{
	return e[2];
}

inline const Vec3 &Vec3::operator+() const
{
	return *this;
}

inline Vec3 Vec3::operator-() const
{
	return Vec3(-e[0], -e[1], -e[2]);
}

inline float Vec3::operator[](int i) const
{
	return e[i];
}

inline float &Vec3::operator[](int i)
{
	return e[i];
}

inline std::istream &operator>>(std::istream &is, Vec3 &t)
{
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

inline std::ostream &operator<<(std::ostream &os, const Vec3 &t)
{
	os << t.e[0] << " " << t.e[1] << " " << t.e[2];
	return os;
}

inline void Vec3::makeUnitVector()
{
	float k = 1.0 / std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2)
{
	return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2)
{
	return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2)
{
	return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2)
{
	return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vec3 operator*(float t, const Vec3 &v)
{
	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator/(Vec3 v, float t)
{
	return Vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

inline Vec3 operator*(const Vec3 &v, float t)
{
	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline float dot(const Vec3 &v1, const Vec3 &v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2)
{
	return Vec3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
	            (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
	            (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}

inline Vec3 &Vec3::operator+=(const Vec3 &v)
{
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

inline Vec3 &Vec3::operator*=(const Vec3 &v)
{
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

inline Vec3 &Vec3::operator/=(const Vec3 &v)
{
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline Vec3 &Vec3::operator-=(const Vec3 &v)
{
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}

inline Vec3 &Vec3::operator*=(const float t)
{
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline Vec3 &Vec3::operator/=(const float t)
{
	float k = 1.0 / t;

	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
	return *this;
}

inline float Vec3::length() const
{
	return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

inline float Vec3::squaredLength() const
{
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

inline Vec3 Vec3::unitVector(const Vec3 &v2)
{
	return v2 / v2.length();
}
