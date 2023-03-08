#pragma once
#include<vector>
#include"Point.h"
#include"Curve.h"

class LoftSurface
{
public:
	std::vector<Curve> surfaces;

	void GenerateSurfaces(std::vector<Point>C1, std::vector<Point>C2, int totalPoints);
};