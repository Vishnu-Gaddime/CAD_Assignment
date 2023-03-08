#include<iostream>
#include<vector>
#include<fstream>
#include"Point.h"
#include"ParabolicArc.h"

using namespace std;

int main()
{
	Point co_ordinates;
	ParabolicArc parabola;

	string filepath;
	cout << "Enter the filepath" << endl;
	cin >> filepath;

	vector<Point> tempVec;
	double x, y, z;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter point" << i << " for parabolicArc" << endl;
		cin >> x >> y >> z;
		co_ordinates.GetPoint(x, y, z);
		tempVec.push_back(co_ordinates);
	}

	int numOfPoints;
	cout << "Enter the number of Points" << endl;
	cin >> numOfPoints;

	parabola.parabolicArcs = parabola.GenerateParabolicArc(tempVec, numOfPoints);
	tempVec.clear();

	ofstream outfile;
	string savepath = filepath + "parabolicArc.dat";
	outfile.open(savepath);

	for (int i = 0; i < parabola.parabolicArcs.size(); i++)
	{
		outfile << parabola.parabolicArcs[i].x << " " << parabola.parabolicArcs[i].y << " " << parabola.parabolicArcs[i].z << endl;
	}
	outfile.close();
	return EXIT_SUCCESS;
}