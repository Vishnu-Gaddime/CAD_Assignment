#include<iostream>
#include<vector>
#include<fstream>
#include"Point.h"
#include"Eclipse.h"

using namespace std;

int main()
{
	Point co_ordinates;
	Eclipse eclipse;

	string filepath;
	cout << "Enter the filepath to generate file to the location" << endl;
	cin >> filepath;
	double x, y, z, radiusA, radiusB;
	int numOfPoints;

	cout << "Enter the Center Point of Eclipse" << endl;
	cin >> x >> y >> z;
	cout << "Enter the Radius of Eclipse radiusA and radiusB" << endl;
	cin >> radiusA >> radiusB;
	cout << "Enter the Number of Points" << endl;
	cin >> numOfPoints;

	co_ordinates.GetPoint(x, y, z);
	eclipse.eclipses = eclipse.GenerateEclipse(co_ordinates, radiusA, radiusB, numOfPoints);

	ofstream outfile;
	string savepath = filepath + "Eclipse.dat";
	outfile.open(savepath);

	for (int i = 0; i < eclipse.eclipses.size(); i++)
	{
		outfile << eclipse.eclipses[i].x << " " << eclipse.eclipses[i].y << " " << eclipse.eclipses[i].z << endl;
	}
	outfile.close();

	return EXIT_SUCCESS;
}
