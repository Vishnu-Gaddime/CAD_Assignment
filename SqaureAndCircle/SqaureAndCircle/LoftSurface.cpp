#include<iostream>
#include <vector>
#include"Point.h"
#include"Circle.h"
#include"Square.h"
#include"LoftSurface.h"

using namespace std;

void LoftSurface::GenerateSurfaces(std::vector<Point>Circles, std::vector<Point>Squares, int totalPoints)
{
	if (Circles.size() != Squares.size())
	{
		cout << "Number of Points are different" << endl;
	}

	Curve cur;
	double dv = 1.0 / totalPoints;
	for (double v = 0; v <= 1; v += dv)
	{
		Point p;
		for (int i = 0; i < Circles.size(); i++)
		{
			double x = Circles[i].x * (1 - v) + Squares[i].x * v;
			double y = Circles[i].y * (1 - v) + Squares[i].y * v;
			double z = Circles[i].z * (1 - v) + Squares[i].z * v;
			p.GetPoint(x, y, z);
			cur.curve.push_back(p);
		}
		surfaces.push_back(cur);
	}
}