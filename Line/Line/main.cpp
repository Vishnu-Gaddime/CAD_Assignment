#include<iostream>
#include<vector>
#include<fstream>
#include"Point.h"
#include"Line.h"

using namespace std;

int main()
{
	Point co_ordinates;
	Line line;

	string filepath;
	cout << "Enter the filepath" << endl;
	cin >> filepath;

	vector<Point> tempVec;
	double x, y, z;
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter point P" << i << " for line" << endl;
		cin >> x >> y >> z;
		co_ordinates.GetPoint(x, y, z);
		tempVec.push_back(co_ordinates);
	}

	int numOfPoints;
	cout << "Enter the number of Points" << endl;
	cin >> numOfPoints;

	line.lines = line.GenerateLine(tempVec, numOfPoints);
	tempVec.clear();

	ofstream outfile;
	string savepath = filepath + "Line.dat";
	outfile.open(savepath);

	for (int i = 0; i < line.lines.size(); i++)
	{
		outfile << line.lines[i].x << " " << line.lines[i].y << " " << line.lines[i].z << endl;
	}
	outfile.close();
	return EXIT_SUCCESS;
}