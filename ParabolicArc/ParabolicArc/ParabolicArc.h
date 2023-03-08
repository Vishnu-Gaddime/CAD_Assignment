#pragma once
#include<vector>
#include"Point.h"

class ParabolicArc
{
public:
	std::vector<Point> parabolicArcs;

	std::vector<Point> GenerateParabolicArc(std::vector<Point> inputPoints, int numOfPoints);
};