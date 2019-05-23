#include "PpmDrawer.h"

#include <fstream>
#include <iostream>
#include "Color.h"

PpmDrawer::PpmDrawer() = default;

PpmDrawer::PpmDrawer(std::string &fileName, int nX, int nY)
{
	this->fileName = fileName;
	this->nX = nX;
	this->nY = nY;
}

PpmDrawer::PpmDrawer(std::string fileName, int nX, int nY)
{
	this->fileName = std::move(fileName);
	this->nX = nX;
	this->nY = nY;
}

void PpmDrawer::write(std::vector<Vec3> &points)
{
	std::ofstream fOut;
	fOut.open(this->fileName);

	fOut << "P3" << std::endl;
	fOut << this->nX << " " << this->nY << std::endl;
	fOut << 255 << std::endl;
	for (Vec3 &point : points)
	{
		fOut << point.toColor(2) << std::endl;
	}

	fOut.close();
}

