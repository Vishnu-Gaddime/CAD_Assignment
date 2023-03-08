#pragma once
#include<vector>
#include"Point.h"

class Circle
{
public:
	std::vector<Point> circles;

	std::vector<Point> GenerateCircle(Point co_ordinates,double radius, int numOfPoints);
};
