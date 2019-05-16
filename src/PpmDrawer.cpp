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

void PpmDrawer::write(std::vector<Color> &points)
{
	std::ofstream fOut;
	fOut.open(fileName);

	fOut << "P3" << std::endl;
	fOut << nX << " " << nY << std::endl;
	fOut << 255 << std::endl;
	for (Color &point : points)
	{
		fOut << point << std::endl;
	}

	fOut.close();
}

