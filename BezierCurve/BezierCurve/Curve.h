#pragma once
#include<vector>
#include"Point.h"

class CubicCurve
{
public:
	std::vector<Point> cubicCurves;

	std::vector<Point> GenerateCubicCurve(std::vector<Point> inputPoints, int numOfPoints);
};