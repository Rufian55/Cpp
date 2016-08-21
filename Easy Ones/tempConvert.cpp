/****************************************************************************
** Author: Chris Kearns
** Date: 10/8/2015
** Description: Script that converts user inputted Celsius
** temperature into Fahrenheit and outputs the value.
****************************************************************************/
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main() {
	float celsius, fahrenheit;

	cout << std::fixed << std::setprecision(2);

	cout << "Please enter a Celsius temperature." << endl;

	cin >> celsius;

	fahrenheit = ((9.0 / 5.0) * celsius) + 32;

	cout << "The equivalent Fahrenheit temperature is:" << fahrenheit;

	return 0;
}