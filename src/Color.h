#pragma once


class Color
{
public:
	int e[3];

	Color();
	Color(int r, int g, int b);

	inline int r();
	inline int g();
	inline int b();

	inline const Color& operator+() const;
	inline int operator[](int i) const;
	inline int& operator[](int i);

	inline Color& operator+=(const Color &color);
	inline Color& operator-=(const Color &color);
};