/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/04/2015
** Description: geomMain.cpp program will create a line segment from two point's x,y coordinates and 
** returns the distance bewteen the lineSegment's end points and the slope of the lineSegment. All 
** arguments passed by value.
**********************************************************************************************************/
#include "Point.hpp"
#include "LineSegment.hpp" 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	double x1, y1, x2, y2;
	cout << "Enter your first point's X value and press <Enter>: ";
	cin >> x1;
	cout << "Enter your first point's Y value and press <Enter>: ";
	cin >> y1;
	cout << "Enter your second point's X value and press <Enter>: ";
	cin >> x2;
	cout << "Enter your second point's Y value and press <Enter>: ";
	cin >> y2;

	Point p1(x1, y1);
	Point p2(x2, y2);

	double var_x1 = p1.getXCoord();
	cout << "p1.x = " << var_x1 << endl;
	
	double var_y1 = p1.getYCoord();
	cout << "p1.y = " << var_y1 << endl;
	
	double var_x2 = p2.getXCoord();
	cout << "p2.x = " << var_x2 << endl;
	
	double var_y2 = p2.getYCoord();
	cout << "p2.y = " << var_y2 << endl;
	
	double dist = p1.distanceTo(p2);
	cout << "Distance = " << dist << endl;
	
	LineSegment ls1(p1, p2);
	
	double length = ls1.length();
	cout << "ls1 length = " << length << endl;

	double slope = ls1.slope();
	cout << "ls1 slope = " << slope << endl;

	return 0;
}