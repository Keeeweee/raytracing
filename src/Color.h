#pragma once

#include <fstream>

class Color
{
public:
	int e[3]{};

	Color()
	{
		e[0] = 0;
		e[1] = 0;
		e[2] = 0;
	};

	Color(int r, int g, int b)
	{
		e[0] = r;
		e[1] = g;
		e[2] = b;
	}


	Color(double r, double g, double b)
	{
		e[0] = int(255.99 * r);
		e[1] = int(255.99 * g);
		e[2] = int(255.99 * b);
	}

	inline int r();
	inline int g();
	inline int b();

	inline const Color& operator+() const;
	inline int operator[](int i) const;
	inline int& operator[](int i);

	inline Color& operator+=(const Color &color);
	inline Color& operator-=(const Color &color);

	friend Color operator+(const Color &c1, const Color &c2);
	friend Color operator-(const Color &c1, const Color &c2);

	friend Color operator*(float t, const Color &v);
	friend Color operator/(const Color &v, int t);

	friend std::ofstream &operator<<(std::ofstream &ofs, const Color &t);
};

int Color::r()
{
	return e[0];
}

int Color::g()
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

inline std::ofstream &operator<<(std::ofstream &ofs, const Color &t)
{
	ofs << t[0] << " " <<  t[1] << " " << t[2];
	return ofs;
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

inline Color operator*(float t, const Color &v)
{
	return Color((int)(t * v.e[0]), (int)(t * v.e[1]), (int)(t * v.e[2]));
}

inline Color operator/(const Color &v, int t)
{
	return Color((int)(v.e[0] / t), (int)(v.e[1] / t), (int)(v.e[2] / t));
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
