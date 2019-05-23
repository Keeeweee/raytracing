#include <vector>

#include <iostream>
#include "Ray.h"
#include "shapes/Sphere.h"
#include "shapes/ShapeList.h"
#include "float.h"
#include "PpmDrawer.h"
#include "Camera.h"
#include "Utils.h"
#include "materials/Lambertian.h"
#include "materials/Metal.h"
#include "materials/Dielectric.h"
#include <random>
#include <chrono>

using namespace std;

int main()
{
	string imagesPath = "../images/";

	vector<Vec3> points = vector<Vec3>();

	ShapeList world;

	world.append(new Sphere(Vec3(0., 0., -1.), 0.5, new Lambertian(Vec3(0.1, 0.2, 0.5))));

	world.append(new Sphere(Vec3(0., -100.5, -1.), 100, new Lambertian(Vec3(0.8, 0.8, 0.0))));

	world.append(new Sphere(Vec3(1., 0., -1.), 0.5, new Metal(Vec3(0.8, 0.6, 0.3), 0.3)));

	world.append(new Sphere(Vec3(-1., 0., -1.), 0.5, new Dielectric(1.5)));
	world.append(new Sphere(Vec3(-1., 0., -1.), -0.45, new Dielectric(5.5)));

	float t = 20.;
	float k = 5.01083 * (world.list.size() - 1);
	float n = pow((t / k), 1./3.);
	n = n > 6 ? 6 : n;
	n = n < 1 ? 1 : n;
	n = 1.;
	cout << "n = " << n << endl;
	int nx = int(200 * n);
	int ny = int(100 * n);
	int ns = int(100 * n);

	cout << "nx = " << nx << endl;
	cout << "ny = " << ny<< endl;
	cout << "ns = " << ns << endl;

	cout << "Estimated time: " << k * pow(n, 3) << endl;



	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	int count = 0;
	for (int j = ny - 1; j >= 0; j--)
	{
		cout << ((float)count*100) / ny << '%' << '\r';
		count++;
		for (int i = 0; i < nx; i++)
		{
			Vec3 color(0., 0., 0);
			Camera camera(90, float(nx) / float(ny));
			for (int s = 0; s < ns; ++s)
			{
				float u = float(i + random()) / float(nx);
				float v = float(j + random()) / float(ny);

				Ray ray = camera.getRay(u, v);

				color += ray.getColor(world, 0);
			}

			points.push_back(color / ns);
		}
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	float duration = (float) std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000000;

	cout << "Time: " << duration << "s" << endl;

	string fileName = "10_glass_bubble_lambertian_and_metal_spheres.ppm";
	PpmDrawer drawer = PpmDrawer(imagesPath + fileName, nx, ny, 2);
	drawer.write(points);
}