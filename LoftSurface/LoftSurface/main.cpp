#include<iostream>
#include<vector>
#include<fstream>
#include"Point.h"
#include"Circle.h"
#include"Eclipse.h"
#include"LoftSurface.h"
#include"Curve.h"

using namespace std;

int main()
{
	Point co_ordinates;
	Circle circle;
	Eclipse eclipse;
	LoftSurface loftsurface;

	string filepath;
	cout << "Enter the filepath to generate file to the location" << endl;
	cin >> filepath;
	double x, y, z, radiusA, radiusB;
	cout << "Enter the Center Point of circle" << endl;
	cin >> x >> y >> z;
	cout << "Enter the Radius of circle" << endl;
	cin >> radiusA;
	int numOfPoints;
	cout << "Enter the Number of Points" << endl;
	cin >> numOfPoints;

	co_ordinates.GetPoint(x, y, z);
	circle.circles = circle.GenerateCircle(co_ordinates, radiusA, numOfPoints);

	cout << "Enter the Center Point of Eclipse" << endl;
	cin >> x >> y >> z;
	cout << "Enter the Radius of Eclipse radiusA and radiusB" << endl;
	cin >> radiusA >> radiusB;
	cout << "Enter the Number of Points" << endl;
	cin >> numOfPoints;

	co_ordinates.GetPoint(x, y, z);
	eclipse.eclipses = eclipse.GenerateEclipse(co_ordinates, radiusA, radiusB, numOfPoints);

	loftsurface.GenerateSurfaces(circle.circles, eclipse.eclipses, 30);

	ofstream outfile;
	string savepath = filepath + "CircleAndEclipse.dat";
	outfile.open(savepath);

	for (int i = 0; i < circle.circles.size(); i++)
	{
		for (int j = 0; j < loftsurface.surfaces[i].curve.size(); j++)
		{
			outfile << loftsurface.surfaces[i].curve[j].x << " " << loftsurface.surfaces[i].curve[j].y << " " << loftsurface.surfaces[i].curve[j].z << endl;
		}
	}
	outfile.close();

	return EXIT_SUCCESS;
}