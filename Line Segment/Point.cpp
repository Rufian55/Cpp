/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/04/2015
** Description: Point.cpp is the Point class function implementation file and as such has the
** Point.hpp specification file included.  All arguments passed by value.
**********************************************************************************************************/
#include "Point.hpp"
#include <cmath> // sqrt().

Point::Point(double x, double y) {
	setXCoord(x);
	setYCoord(y);
}

// Default Point constructor that simply sets x and y to zero.
Point::Point() {
	setXCoord(0.0);
	setYCoord(0.0);
}

// Our setXCoord() method that takes one argument - the Point's "x" value.
void Point::setXCoord(double x) {
	xCoord = x;
}

// Our setYCoord() method that takes one argument - the Point's "y" value
void Point::setYCoord(double y) {
	yCoord = y;
}

// Our getXCoord() method that is designed to be called with the dot operator and returns a Point's "x" value.
double Point::getXCoord() {
	double x = xCoord;
	return x;
}

// Our getYCoord() method that is designed to be called with the dot operator and returns a Point's "y" value.
double Point::getYCoord() {
	double y = yCoord;
	return y;
}

/*********************************************************************************************************
					Function: distanceTo()
** Description: Returns the distance between two points. Utilized by appending the function call
** after the first point via a dot operator with the second point taken as a parameter of type Point.
** Example: double dist = p1.distanceTo(p2);
**
**********************************************************************************************************/
double Point::distanceTo(Point farPoint) {
	double dx = getXCoord() - farPoint.getXCoord();
	double dy = getYCoord() - farPoint.getYCoord();
	double dist_2 = sqrt(pow(dx,2) + pow(dy,2));
	return dist_2;
}
