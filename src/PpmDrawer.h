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
	float gamma;
public:
	PpmDrawer();

	PpmDrawer(std::string &fileName, int nX, int nY, float gamma);

	PpmDrawer(std::string fileName, int nX, int nY, float gamma);

	void write(std::vector<Vec3> &points);
};