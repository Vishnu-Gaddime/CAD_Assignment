#include"Point.h"
#include"ParabolicArc.h"
#include<vector>

std::vector<Point> ParabolicArc::GenerateParabolicArc(std::vector<Point> inputPoints, int numOfPoints)
{
	Point p;
	double du = 1.0 / numOfPoints;
	for (double u = 0; u <= 1; u += du)
	{
		double x = inputPoints[0].x * (1 - u) * (1 - u) + 2 * inputPoints[1].x * (1 - u) *  u + inputPoints[2].x * u * u;
		double y = inputPoints[0].y * (1 - u) * (1 - u) + 2 * inputPoints[1].y * (1 - u) * u + inputPoints[2].y * u * u;
		double z = inputPoints[0].z * (1 - u) * (1 - u) + 2 * inputPoints[1].z * (1 - u) * u + inputPoints[2].z * u * u;
		p.GetPoint(x, y, z);
		parabolicArcs.push_back(p);
	}
	return parabolicArcs;
}