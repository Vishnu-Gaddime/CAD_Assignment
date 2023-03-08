#include<iostream>
#include<vector>
#include<fstream>
#include"Point.h"
#include"Circle.h"

using namespace std;

int main()
{
	Point co_ordinates;
	Circle circle;

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

	ofstream outfile;
	string savepath = filepath + "Circle.dat";
	outfile.open(savepath);

	for (int i = 0; i < circle.circles.size(); i++)
	{
		outfile << circle.circles[i].x << " " << circle.circles[i].y << " " << circle.circles[i].z << endl;
	}
	outfile.close();

	return EXIT_SUCCESS;
}