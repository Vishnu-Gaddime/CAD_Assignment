#pragma once
#include<vector>
#include"Point.h"

class Line
{
public:
	std::vector<Point> lines;

	std::vector<Point> GenerateLine(std::vector<Point> inputPoints, int numOfPoints);
};