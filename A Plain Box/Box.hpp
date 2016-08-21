/**********************************************************************************************************
** Author: Christopher G. Kearns (kearnsc)
** Date: 10/28/2015
** Description: Box.hpp header file is the class specification file for Box.cpp and as such
** must be included.  Please note, program will handle negative values and zero as parameters, as well
** as client calls with no, one, two or three parameters (via construtor overloading).  Zero and omitted
** parameters will default to 1.0, and negative value parameters will be converted to their absolute value.
**********************************************************************************************************/
#ifndef BOX_HPP
#define BOX_HPP 

//Box class declaration
class Box {
	private:
		double height;
		double width;
		double length;
	public:
		Box();
		Box(double height, double width, double length);
		Box(double height, double width);
		Box(double height);

		// Setter function prototypes.
		double setHeight(double);
		double setWidth(double);
		double setLength(double);

		// Getter function prototypes.
		double getVolume();
		double getSurfaceArea();
};
#endif