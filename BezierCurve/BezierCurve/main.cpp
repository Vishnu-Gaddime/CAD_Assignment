#include<iostream>
#include<vector>
#include<fstream>
#include"Point.h"
#include"Curve.h"

using namespace std;

int main()
{
	Point co_ordinates;
	CubicCurve cubicCurve;

	string filepath;
	cout << "Enter the filepath" << endl;
	cin >> filepath;

	vector<Point> tempVec;
	double x, y, z;
	for (int i = 0; i < 4; i++)
	{
		cout << "Enter point" << i << " for Bezier Curve" << endl;
		cin >> x >> y >> z;
		co_ordinates.GetPoint(x, y, z);
		tempVec.push_back(co_ordinates);
	}

	int numOfPoints;
	cout << "Enter the number of Points" << endl;
	cin >> numOfPoints;

	cubicCurve.cubicCurves = cubicCurve.GenerateCubicCurve(tempVec, numOfPoints);
	tempVec.clear();

	ofstream outfile;
	string savepath = filepath + "cubicCurve.dat";
	outfile.open(savepath);

	for (int i = 0; i < cubicCurve.cubicCurves.size(); i++)
	{
		outfile << cubicCurve.cubicCurves[i].x << " " << cubicCurve.cubicCurves[i].y << " " << cubicCurve.cubicCurves[i].z << endl;
	}
	outfile.close();
	return EXIT_SUCCESS;
}