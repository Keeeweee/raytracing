#pragma once

class Vec3
{
public:
    float e[3];

    Vec3();
    Vec3(float e0, float e1, float e2);

    inline float x();
    inline float y();
    inline float z();

    inline const Vec3& operator+() const;
    inline Vec3 operator-() const;
    inline float operator[](int i) const;
    inline float& operator[](int i);

    inline Vec3& operator+=(const Vec3 &v2);
    inline Vec3& operator-=(const Vec3 &v2);
    inline Vec3& operator*=(const Vec3 &v2);
    inline Vec3& operator/=(const Vec3 &v2);

    inline Vec3& operator*=(float t);
    inline Vec3& operator/=(float t);

    inline float length() const;
    inline float squaredLength() const;
    inline void makeUnitVector();
    inline Vec3 unitVector(const Vec3 &v2);
};