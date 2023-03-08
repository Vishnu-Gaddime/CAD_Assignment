#include<iostream>
#include <vector>
#include"Point.h"
#include"Circle.h"
#include"Eclipse.h"
#include"LoftSurface.h"

using namespace std;

void LoftSurface::GenerateSurfaces(std::vector<Point>Circles, std::vector<Point>Eclipses, int totalPoints)
{
	if (Circles.size() != Eclipses.size())
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
			double x = Circles[i].x * (1 - v) + Eclipses[i].x * v;
			double y = Circles[i].y * (1 - v) + Eclipses[i].y * v;
			double z = Circles[i].z * (1 - v) + Eclipses[i].z * v;
			p.GetPoint(x, y, z);
			cur.curve.push_back(p);
		}
		surfaces.push_back(cur);
	}
}