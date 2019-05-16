#include "Color.h"
#include <iostream>

Color::Color()
{

}

Color::Color(int r, int g, int b)
{
	e[0] = r;
	e[1] = g;
	e[2] = b;
}

int Color::g()
{
	return e[0];
}

int Color::r()
{
	return e[1];
}

int Color::b()
{
	return e[2];
}

const Color &Color::operator+() const
{
	return *this;
}

int Color::operator[](int i) const
{
	return e[i];
}

int &Color::operator[](int i)
{
	return e[i];
}

inline std::istream &operator>>(std::istream &is, Color &t)
{
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

inline std::ostream &operator<<(std::ostream &os, const Color &t)
{
	os << t.e[0] << " " << t.e[1] << " " << t.e[2];
	return os;
}

inline Color &Color::operator+=(const Color &color)
{
	e[0] = color.e[0] + e[0] >= 255 ? 255 : e[0] + color.e[0];
	e[1] = color.e[1] + e[1] >= 255 ? 255 : e[1] + color.e[1];
	e[2] = color.e[2] + e[2] >= 255 ? 255 : e[2] + color.e[2];

	return *this;
}

inline Color &Color::operator-=(const Color &color)
{
	e[0] = color.e[0] >= e[0] ? 0 : e[0] - color.e[0];
	e[1] = color.e[1] >= e[1] ? 0 : e[1] - color.e[1];
	e[2] = color.e[2] >= e[2] ? 0 : e[2] - color.e[2];
	return *this;
}

inline Color operator+(const Color &c1, const Color &c2)
{
	int r = c1.e[0] + c2[0] >= 255 ? 255 : c1[0] + c2.e[0];
	int g = c1.e[1] + c2[1] >= 255 ? 255 : c1[1] + c2.e[1];
	int b = c1.e[2] + c2[2] >= 255 ? 255 : c1[2] + c2.e[2];

	return Color(r, g, b);
}

inline Color operator-(const Color &c1, const Color &c2)
{
	int r = c1.e[0] <= c2[0] ? 0 : c1[0] - c2.e[0];
	int g = c1.e[1] <= c2[1] ? 0 : c1[1] - c2.e[1];
	int b = c1.e[2] <= c2[2] ? 0 : c1[2] - c2.e[2];

	return Color(r, g, b);
}
