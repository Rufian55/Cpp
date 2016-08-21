/****************************************************************************************************
** Author: Chris Kearns
** Date: 10/21/2015

** Description: a function to be included in other programs as needed that accepts 
** a time value in seconds as a double and returns the "distance" fallen expressed as a double
** based upon the physics equation d = (1/2)gt^2 where d is distance in meters, g is 9.8 
** (gravitational constant) and t is time or by the function's
** input parameter (in this case "theTime") which is passed by value.
****************************************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>	//pow().
#include <iomanip> //setprecision.

// Function Prototype.
double fallDistance(double);

int main() {
	double distance;	// Distance in meters.
	double fallTime;	// Time in seconds the object has been falling.

	cout << "Please enter the exact amount of time you've been " << endl;
	cout << "falling from a perfectly good aircraft in seconds." << endl;
	cin >> fallTime;

	distance = fallDistance(fallTime);

	cout << std::setprecision(1) << std::showpoint << std::fixed;
	cout << "You've fallen " << distance << " meters." << endl;
	return 0;
}

/*********************************8********************************************************************
** Description: Function fallDistance() accepts a double "theTime" (in this case, time in seconds) as
**   an argument and utilizing the formulae d = (1/2)gt^2 where d is distance in meters, g is 9.8 
**   (gravitational constant) and theTime is time in seconds.
*******************************************************************************************************/
double fallDistance(double theTime) {
	double distance;
	const double GRAVITY = 9.8;	// Gravitational constant for planet Earth.
	distance = 0.5 * GRAVITY * pow(theTime, 2);
	return distance;
}