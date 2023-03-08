#include"Point.h"
#include"Line.h"
#include<vector>

std::vector<Point> Line::GenerateLine(std::vector<Point> inputPoints, int numOfPoints)
{
	Point p;
	double du = 1.0 / numOfPoints;
	for (double u = 0; u <= 1; u += du)
	{
		double x = inputPoints[0].x * (1 - u) + inputPoints[1].x * u;
		double y = inputPoints[0].y * (1 - u) + inputPoints[1].y * u;
		double z = inputPoints[0].z * (1 - u) + inputPoints[1].z * u;
		p.GetPoint(x, y, z);
		lines.push_back(p);
	}
	return lines;
}