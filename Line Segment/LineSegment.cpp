/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/04/2015
** Description: LineSegment.cpp is the LineSegment class function implementation file and as
** such has the LineSegment.hpp specification file included.  Program will create a line segment from two
** Points and has two methods - length() [returns distance bewteen lineSegment end points] and slope()
** [returns slope of the lineSegment]. All arguments passed by value.
**********************************************************************************************************/
#include "LineSegment.hpp"

void LineSegment::setEnd1(Point p1) {
	endP_1 = p1;
}

void LineSegment::setEnd2(Point p2) {
	endP_2 = p2;
}

void LineSegment::getEnd1(Point p1) {
	double x1 = p1.getXCoord();
	double y1 = p1.getYCoord();
}

void LineSegment::getEnd2(Point p2) {
	double x2 = p2.getXCoord();
	double y2 = p2.getYCoord();
}

LineSegment::LineSegment(Point p1, Point p2) {
	setEnd1(p1);
	setEnd2(p2);
}
// (Note there is no default LineSegment constructor as that would be "Pointless" :)


/*********************************************************************************************************
					Function: length()
** Description: Returns the distance between the two Points of a LineSegment. Utilized by appending the
** function call distanceTo() [see file Point.cpp] after the first point via a dot operator with the 
** second point taken as a parameter of type Point.
** Example: double length = ls1.length(); where ls1 is a lineSegment.
**
**********************************************************************************************************/
double LineSegment::length() {
	Point p3 = endP_1; 
	Point p4 = endP_2;
	double len = p3.distanceTo(p4);
	return len;
}


/*********************************************************************************************************
					Function: slope()
** Description: Returns the slope of the lineSegment between two Points. Utilized by first extracting our
** lineSegment's Point's x and y coordinates and applying those to the mathmatical method m=dy/dx.
** Example: double slope = ls1.slope(); where ls1 is a lineSegment.
**
**********************************************************************************************************/
double LineSegment::slope() {
	Point p3 = endP_1;
	getEnd1(p3);
	Point p4 = endP_2;
	getEnd2(p4);
	
	double dx = p3.getXCoord() - p4.getXCoord();
	double dy = p3.getYCoord() - p4.getYCoord();
	double _slope = dy/dx;

	return _slope;
}
