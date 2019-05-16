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
            Color col(float(i) / float(nx), float(j) / float(ny), 0.2);

            points.push_back(col);
        }
    }

    string fileName = "02_color_gradient.ppm";
    PpmDrawer drawer = PpmDrawer(imagesPath + fileName, nx, ny);
    drawer.write(points);
}