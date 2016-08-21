/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/04/2015
** Description: LineSegment.hpp header file is the class specification file for 
** LineSegment.cpp and as such must be included.  Note inclusion of Point.hpp.
**********************************************************************************************************/
#ifndef LINE_SEGMENT_HPP 
#define LINE_SEGMENT_HPP
#include "Point.hpp"

class LineSegment {
	private:
		Point endP_1;
		Point endP_2;
	public:
		void setEnd1(Point);
		void setEnd2(Point);

	// Our getter function prototypes.
	void getEnd1(Point);
	void getEnd2(Point);

	// Our LineSegment() function prototype. 
	LineSegment(Point, Point);

	// Our length() and slope() function prototypes.
	double length();
	double slope();
};
#endif