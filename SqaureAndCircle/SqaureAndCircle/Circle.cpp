#include <vector>
#include"Point.h"
#include"Circle.h"

std::vector<Point> Circle::GenerateCircle(Point co_ordinates, double radius, int numOfPoints)
{
	Point points;
	double du = 2 * 3.14 / (numOfPoints + 1);
	for (double u = 0; u <= 2 * 3.14; u += du)
	{
		double x = cos(u) * radius + co_ordinates.x;
		double y = sin(u) * radius + co_ordinates.y;
		double z = co_ordinates.z;
		points.GetPoint(x, y, z);
		circles.push_back(points);
	}
	return circles;
}