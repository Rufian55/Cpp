/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/04/2015
** Description: Point.hpp header file is the class specification file for Point.cpp and as such
** must be included.
**********************************************************************************************************/
#ifndef POINT_HPP
#define POINT_HPP

class Point {
	private:
		double xCoord;	// The points x coordinate.
		double yCoord;	// the points y coordinate.
	public:
		Point(double xCoord, double yCoord);

	// Our default constructor for Point class.
	Point();

	// Our setter function prototypes.
	void setXCoord(double);
	void setYCoord(double);

	// Our getter function prototypes.
	double getXCoord();
	double getYCoord();

	// Our distanceTo function prototype 
	double distanceTo(Point);
};
#endif