#include<iostream>
#include<vector>
#include<fstream>
#include"Point.h"
#include"Circle.h"
#include"Square.h"
#include"LoftSurface.h"
#include"Curve.h"

using namespace std;

int main()
{
	Point co_ordinates;
	Circle circle;
	Square square;
	LoftSurface loftsurface;

	string filepath;
	cout << "Enter the filepath to generate file to the location" << endl;
	cin >> filepath;
	double x, y, z, radius;
	cout << "Enter the Center Point of circle" << endl;
	cin >> x >> y >> z;
	cout << "Enter the Radius of circle" << endl;
	cin >> radius;
	int numOfPoints;
	cout << "Enter the Number of Points" << endl;
	cin >> numOfPoints;

	co_ordinates.GetPoint(x, y, z);
	circle.circles = circle.GenerateCircle(co_ordinates, radius, numOfPoints);

	vector<Point> tempVec;
	for (int i = 0; i < 4; i++)
	{
		Point p;
		cout << "Enter the " << i << " point of square" << endl;
		cin >> x >> y >> z;
		p.GetPoint(x, y, z);
		tempVec.push_back(p);
	}
	square.squares = square.GenerateSquare(tempVec, numOfPoints /4);
	//square.squares.erase(square.squares.begin() + 10);

	loftsurface.GenerateSurfaces(circle.circles, square.squares , numOfPoints);

	ofstream outfile;
	string savepath = filepath + "test4.dat";
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