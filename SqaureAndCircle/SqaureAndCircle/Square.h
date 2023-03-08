#pragma once
#include"Point.h"

class Square
{
public:
	std::vector<Point> squares;

	std::vector<Point> GenerateSquare(std::vector<Point>co_ordinates, int numOfPoints);
};