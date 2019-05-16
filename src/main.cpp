#include <vector>

#include <iostream>
#include "Ray.h"
#include "shapes/Sphere.h"
#include "shapes/ShapeList.h"
#include "float.h"
#include "PpmDrawer.h"
#include "Camera.h"
#include <random>

using namespace std;

int main()
{
	string imagesPath = "../images/";
	int n = 5;
	int nx = 200 * n;
	int ny = 100 * n;
	int ns = 100;

	random_device rd;
	mt19937 e2(rd());
	uniform_real_distribution<> dist(0,1);




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
			Color color;
			Camera camera;
			int r = 0;
			int g = 0;
			int b = 0;
			for (int s = 0; s < ns; ++s)
			{
				float u = float(i + dist(e2)) / float(nx);
				float v = float(j + dist(e2)) / float(ny);

				Ray ray = camera.getRay(u, v);

				color = ray.getColor(world);
				r += color.r();
				g += color.g();
				b += color.b();
			}

			Color newColor((int)(r / ns), (int)(g / ns), (int)(b / ns));

			points.push_back(newColor);
		}
	}

	string fileName = "05_normal_gradient_sphere_with_AA.ppm";
	PpmDrawer drawer = PpmDrawer(imagesPath + fileName, nx, ny);
	drawer.write(points);
}