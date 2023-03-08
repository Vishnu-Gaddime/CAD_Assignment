#include<vector>
#include"Point.h"
#include"Square.h"

std::vector<Point> Square::GenerateSquare(std::vector<Point>co_ordinates,int numOfPoints)
{
	Point point;
	double du = 1.0 / numOfPoints;
	/*for (int i = 0; i < 4; i++)
	{
		for (double u = (double)i; u <= 1.0; u += du)
		{
			double x = co_ordinates[0].x * (1 - u) + co_ordinates[1].x * u;
			double y = co_ordinates[0].y * (1 - u) + co_ordinates[1].y * u;
			point.GetPoint(x, y, 0);
			squares.push_back(point);
		}
	}*/


	for (double u = 0; u <= 1.0; u += du)
	{
		double x = co_ordinates[0].x * (1 - u) + co_ordinates[1].x * u;
		double y = co_ordinates[0].y * (1 - u) + co_ordinates[1].y * u;
		double z = co_ordinates[0].z * (1 - u) + co_ordinates[1].z * u;
		point.GetPoint(x, y, z);
		squares.push_back(point);
	}
	for (double u = 0; u <= 1.0; u += du)
	{
		double x = co_ordinates[1].x * (1 - u) + co_ordinates[2].x * u;
		double y = co_ordinates[1].y * (1 - u) + co_ordinates[2].y * u;
		double z = co_ordinates[1].z * (1 - u) + co_ordinates[2].z * u;
		point.GetPoint(x, y, z);
		squares.push_back(point);
	}
	for (double u = 0; u <= 1.0; u += du)
	{
		double x = co_ordinates[2].x * (1 - u) + co_ordinates[3].x * u;
		double y = co_ordinates[2].y * (1 - u) + co_ordinates[3].y * u;
		double z = co_ordinates[2].z * (1 - u) + co_ordinates[3].z * u;
		point.GetPoint(x, y, z);
		squares.push_back(point);
	}
	for (double u = 0; u <= 1.0; u += du)
	{
		double x = co_ordinates[3].x * (1 - u) + co_ordinates[0].x * u;
		double y = co_ordinates[3].y * (1 - u) + co_ordinates[0].y * u;
		double z = co_ordinates[3].z * (1 - u) + co_ordinates[0].z * u;
		point.GetPoint(x, y, z);
		squares.push_back(point);
	}

	return squares;
}