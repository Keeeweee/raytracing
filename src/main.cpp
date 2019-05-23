#include <vector>

#include <iostream>
#include "Ray.h"
#include "shapes/Sphere.h"
#include "shapes/ShapeList.h"
#include "float.h"
#include "PpmDrawer.h"
#include "Camera.h"
#include "Utils.h"
#include <random>
#include <chrono>

using namespace std;

int main()
{
	string imagesPath = "../images/";

	float t = 60.;
	float k = 5.01083;
	int n = (int)pow((t / k), 1./3.);
	n = n > 6 ? 6 : n;
	n = n < 1 ? 1 : n;
	cout << "n = " << n << endl;
	int nx = 200 * n;
	int ny = 100 * n;
	int ns = 100 * n;

	cout << "Estimated time: " << k * pow(n, 3) << endl;


	vector<Vec3> points = vector<Vec3>();

	ShapeList world;

	Sphere sphere1(Vec3(0., 0., -1.), 0.5);
	world.append(&sphere1);

	Sphere sphere2(Vec3(0., -100.5, -1.), 100);
	world.append(&sphere2);

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	int count = 0;
	for (int j = ny - 1; j >= 0; j--)
	{
		cout << ((float)count*100) / ny << '%' << '\r';
		count++;
		for (int i = 0; i < nx; i++)
		{
			Vec3 color(0., 0., 0);
			Camera camera;
			for (int s = 0; s < ns; ++s)
			{
				float u = float(i + random()) / float(nx);
				float v = float(j + random()) / float(ny);

				Ray ray = camera.getRay(u, v);

				color += ray.getColor(world);
			}

			points.push_back(color / ns);
		}
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	float duration = (float) std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count() / 1000000;

	cout << "Time: " << duration << "s" << endl;

	string fileName = "05_normal_gradient_sphere_with_AA2.ppm";
	PpmDrawer drawer = PpmDrawer(imagesPath + fileName, nx, ny);
	drawer.write(points);
}