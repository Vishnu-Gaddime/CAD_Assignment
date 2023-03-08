#include"Point.h"
#include"Curve.h"
#include<vector>

std::vector<Point> CubicCurve::GenerateCubicCurve(std::vector<Point> inputPoints, int numOfPoints)
{
	Point p;
	double du = 1.0 / numOfPoints;
	for (double u = 0; u <= 1; u += du)
	{
		double x = (inputPoints[0].x * (1 - u) * (1 - u) * (1 - u)) + 3 * (inputPoints[1].x * (1 - u) * (1 - u) * u) + 3 * (inputPoints[2].x * (1 - u) * u * u) + (inputPoints[3].x * u * u * u);
		double y = (inputPoints[0].y * (1 - u) * (1 - u) * (1 - u)) + 3 * (inputPoints[1].y * (1 - u) * (1 - u) * u) + 3 * (inputPoints[2].y * (1 - u) * u * u) + (inputPoints[3].y * u * u * u);
		double z = (inputPoints[0].z * (1 - u) * (1 - u) * (1 - u)) + 3 * (inputPoints[1].z * (1 - u) * (1 - u) * u) + 3 * (inputPoints[2].z * (1 - u) * u * u) + (inputPoints[3].z * u * u * u);
		p.GetPoint(x, y, z);
		cubicCurves.push_back(p);
	}
	return cubicCurves;
}