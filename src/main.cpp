#include <vector>

#include <iostream>
#include "Ray.h"
#include "shapes/Sphere.h"
#include "shapes/ShapeList.h"
#include "float.h"
#include "PpmDrawer.h"
#include "Camera.h"


using namespace std;

int main()
{
	string imagesPath = "../images/";
	int n = 1;
	int nx = 200 * n;
	int ny = 100 * n;



	vector<Color> points = vector<Color>();

	ShapeList world;

	Sphere sphere1(Vec3(0., 0., -1.), 0.5);
	world.append(&sphere1);

	Sphere sphere2(Vec3(0., -100.5, -1.), 100);
	world.append(&sphere2);


	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);

			Camera camera;

			Ray r = camera.getRay(u, v);

			Color color = r.getColor(world);
			points.push_back(color);
		}
	}

	string fileName = "04_normal_gradient_sphere.ppm";
	PpmDrawer drawer = PpmDrawer(imagesPath + fileName, nx, ny);
	drawer.write(points);
}