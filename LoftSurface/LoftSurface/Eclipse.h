#pragma once
#include<vector>
#include"Point.h"

class Eclipse
{
public:
	std::vector<Point> eclipses;

	std::vector<Point> GenerateEclipse(Point co_ordinates, double radiusA, double radiusB, int numOfPoints);
};
