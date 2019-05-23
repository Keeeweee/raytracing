#pragma once

#include <string>
#include <vector>

#include "Color.h"
#include "Vec3.h"

class PpmDrawer
{
private:
	std::string fileName;
	int nX, nY;
public:
	PpmDrawer();

	PpmDrawer(std::string &fileName, int nX, int nY);

	PpmDrawer(std::string fileName, int nX, int nY);

	void write(std::vector<Vec3> &points);
};