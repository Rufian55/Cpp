/**********************************************************************************************************
** Author: Chris Kearns
** Date: 10/28/2015
** Description: Box.cpp is the Box class function implementation file and as such has the
** Box.hpp specification file included.  All arguments passed by value.  Please note, program will
** handle negative values and zero as parameters, as well as client calls with no, one, two or three
** parameters (via construtor overloading).  Zero and omitted parameters will default to 1.0, and negative
** value parameters will be converted to their absolute value.
**********************************************************************************************************/
#include "Box.hpp"
#include <stdlib.h>	// abs().

// setHeight function that handles postive, negative, and 0.0 input variables.
double Box::setHeight(double heightIn) {
	if (heightIn > 0.0)
		height = heightIn;
	else if (heightIn == 0.0) {
		height = 1.0;
	}
	else {
		height = abs(heightIn);
	}
}

// setWidth function that handles postive, negative, and 0.0 input variables.
double Box::setWidth(double widthIn) {
	if (widthIn > 0.0) {
		width = widthIn;
	}
	else if (widthIn == 0.0) {
		width = 1.0;
	}
	else {
		width = abs(widthIn);
	}
}

// setLength function that handles postive, negative, and 0.0 input variables.
double Box::setLength(double lengthIn) {
	if (lengthIn > 0.0) {
		length = lengthIn;
	}
	else if (lengthIn == 0.0) {
		length = 1.0;
	}
	else {
		length = abs(lengthIn);
	}
}

// getVolume function that returns the classic L x W x H cubic area.
double Box::getVolume() {
	return length * width * height;
}

/* getSurfaceArea function that returns the surface area of all six sides of
   a cube/rectangle. */
double Box::getSurfaceArea() {
	return (2 * length * width) + (2 * length * height) + (2 * width * height);
}

/* Default constructor that passes "1.0" to the set methods to initialize each
   field to 1.0 when no paramters are included in the client call. */
Box::Box() {
	height = setHeight(1.0);
	width = setWidth(1.0);
	length = setLength(1.0);
}

/* Three parameter constructor that passes argument to respective set methods
   to initialize Box fields (when included in the client call. */
Box::Box(double h, double w, double l) {
	height = setHeight(h);
	width = setWidth(w);
	length = setLength(l);
}

/* Two parameter constructor that passes argument to respective set methods to
   initialize Box fields with 1.0 used as default for client call with just two
   arguments. */
Box::Box(double h, double w) {
	height = setHeight(h);
	width = setWidth(w);
	length = setLength(1.0);
}

/* One parameter constructor that passes argument to respective set methods to
   initialize Box fields with 1.0 used as defaults for client call with just one
   argument. */
Box::Box(double h) {
	height = setHeight(h);
	width = setWidth(1.0);
	length = setLength(1.0);
}


int main() {

	//Test #1, parameters omitted, so defaults from Box.hpp header file are used.
	Box unitBox;

	cout << "boxMain test 1a unitBox volume = " << unitBox.getVolume() << endl;
	cout << endl;
	cout << "boxMain test 1b unitBox surface area = " << unitBox.getSurfaceArea() << endl;
	cout << endl;

	//Test # 2, parameters included in function call.
	Box threeArgBox(3.0, 4.0, 5.0);

	cout << "boxMain test 2a threeArgBox volume = " << threeArgBox.getVolume() << endl;
	cout << endl;
	cout << "boxMain test 2b threeArgBox surface area = " << threeArgBox.getSurfaceArea() << endl;
	cout << endl;

	//Test # 3, two parameters included in function call.
	Box twoArgBox(3.0, 4.0);

	cout << "boxMain test 3a twoArgBox volume = " << twoArgBox.getVolume() << endl;
	cout << endl;
	cout << "boxMain test 2b twoArgBox surface area = " << twoArgBox.getSurfaceArea() << endl;
	cout << endl;

	//Test # 4, one parameter included in function call.
	Box oneArgBox(3.0);

	cout << "boxMain test 4a oneArgBox volume = " << oneArgBox.getVolume() << endl;
	cout << endl;
	cout << "boxMain test 4b oneArgBox surface area = " << oneArgBox.getSurfaceArea() << endl;
	cout << endl;

	//Test #5, parameters gathered individually and passed to getVolume() and getSurfaceArea() by value so we can test! 
	double length, width, height;

	cout << "Welcome to the Box program! This program will prompt you to " << endl;
	cout << "enter your box's length, width, amd height, each formatted as " << endl;
	cout << "a positive double, and return your box's Volume and Surface Area." << endl;
	cout << endl;

	Box	anotherBox;

	cout << "Please enter your box's length formatted as a double (i.e. 7.2)" << endl;
	cin >> length;
	anotherBox.setLength(length);
	cout << "Please enter your box's width formatted as a double (i.e. 6.5)" << endl;
	cin >> width;
	anotherBox.setWidth(width);
	cout << "Please enter your box's height formatted as a double (i.e. 5.8)" << endl;
	cin >> height;
	anotherBox.setHeight(height);

	cout << "anotherBox volume = " << anotherBox.getVolume() << endl;
	cout << endl;
	cout << "anotherBox surface area = " << anotherBox.getSurfaceArea() << endl;

	return 0;
}