#include <iostream>
#include <vector>

#include "Vec3.h"
#include "Color.h"
#include "PpmDrawer.h"
#include "Ray.h"

using namespace std;

int main()
{
	string imagesPath = "../images/";
	int n = 1;
	int nx = 200 * n;
	int ny = 100 * n;

	Vec3 lowerLeftCorner(-2., -1., -1.);
	Vec3 horizontal(4., 0., 0.);
	Vec3 vertical(0., 2., 0.);
	Vec3 origin(0., 0., 0.);

	vector<Color> points = vector<Color>();

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);

			Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical);

			Color color = r.getColor();
			points.push_back(color);
		}
	}

	string fileName = "02_blue_gradient.ppm";
	PpmDrawer drawer = PpmDrawer(imagesPath + fileName, nx, ny);
	drawer.write(points);
}