#include <iostream>
#include <vector>

#include "Vec3.h"
#include "Color.h"
#include "PpmDrawer.h"

using namespace std;

int main()
{
	string imagesPath = "../images/";
    int n = 1;
	int nx = 200*n;
    int ny = 100*n;

	vector<Color> points = vector<Color>();

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            points.emplace_back(ir, ig, ib);
        }
    }

    string fileName = "01_color_gradient.ppm";
    PpmDrawer drawer = PpmDrawer(imagesPath + fileName, nx, ny);
    drawer.write(points);
}