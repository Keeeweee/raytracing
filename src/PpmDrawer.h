#pragma once

#include <string>
#include <vector>

#include "Color.h"

class PpmDrawer
{
private:
	std::string fileName;
	int nX, nY;
public:
	PpmDrawer();

	PpmDrawer(std::string &fileName, int nX, int nY);

	void write(std::vector<Color> &points);
};