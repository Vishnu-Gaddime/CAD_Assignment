#include<iostream>
#include<vector>
#include<fstream>
#include"Point.h"
#include"Line.h"
#include"CubicCurve.h"
#include"Curve.h"
#include"LoftSurface.h"

using namespace std;

int main()
{
	Point co_ordinates;
	Line line;
	CubicCurve cubicCurve;
	LoftSurface loftsurface;

	string filepath;
	cout << "Enter the filepath" << endl;
	cin >> filepath;

	vector<Point> tempVec;
	double x, y, z;
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter point" << i << " for line" << endl;
		cin >> x >> y >> z;
		co_ordinates.GetPoint(x, y, z);
		tempVec.push_back(co_ordinates);
	}

	int numOfPoints;
	cout << "Enter the number of Points" << endl;
	cin >> numOfPoints;

	line.lines = line.GenerateLine(tempVec, numOfPoints);
	tempVec.clear();

	for (int i = 0; i < 4; i++)
	{
		cout << "Enter point" << i << " for Bezier Curve" << endl;
		cin >> x >> y >> z;
		co_ordinates.GetPoint(x, y, z);
		tempVec.push_back(co_ordinates);
	}

	cubicCurve.cubicCurves = cubicCurve.GenerateCubicCurve(tempVec, numOfPoints);

	loftsurface.GenerateSurfaces(line.lines, cubicCurve.cubicCurves, numOfPoints);

	ofstream outfile;
	string savepath = filepath + "test5.dat";
	outfile.open(savepath);

	for (int i = 0; i < line.lines.size(); i++)
	{
		for (int j = 0; j < loftsurface.surfaces[i].curve.size(); j++)
		{
			outfile << loftsurface.surfaces[i].curve[j].x << " " << loftsurface.surfaces[i].curve[j].y << " " << loftsurface.surfaces[i].curve[j].z << endl;
		}
	}
	outfile.close();

	return EXIT_SUCCESS;
}