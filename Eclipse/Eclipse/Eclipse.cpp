#include <vector>
#include"Point.h"
#include"Eclipse.h"

std::vector<Point> Eclipse::GenerateEclipse(Point co_ordinates, double radiusA, double radiusB, int numOfPoints)
{
	Point points;
	double du = 2 * 3.14 / numOfPoints;
	for (double u = 0; u <= 2 * 3.14; u += du)
	{
		double x = cos(u) * radiusA + co_ordinates.x;
		double y = sin(u) * radiusB + co_ordinates.y;
		double z = co_ordinates.z;
		points.GetPoint(x, y, z);
		eclipses.push_back(points);
	}
	return eclipses;
}