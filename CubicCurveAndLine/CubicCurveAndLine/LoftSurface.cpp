#include<iostream>
#include <vector>
#include"Point.h"
#include"CubicCurve.h"
#include"Line.h"
#include"LoftSurface.h"

using namespace std;

void LoftSurface::GenerateSurfaces(std::vector<Point>Lines, std::vector<Point>CubicCurves, int totalPoints)
{
	if (Lines.size() != CubicCurves.size())
	{
		cout << "Number of Points are different" << endl;
	}

	Curve cur;
	double dv = 1.0 / totalPoints;
	for (double v = 0; v <= 1; v += dv)
	{
		Point p;
		for (int i = 0; i < Lines.size(); i++)
		{
			double x = Lines[i].x * (1 - v) + CubicCurves[i].x * v;
			double y = Lines[i].y * (1 - v) + CubicCurves[i].y * v;
			p.GetPoint(x, y, 0);
			cur.curve.push_back(p);
		}
		surfaces.push_back(cur);
	}
}