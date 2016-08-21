/********************************************************************************************************
** Author: Chris Kearns
** Date: 10/21/2015
** Description: a function to be included in other programs as needed that accepts 
** three integers passed by reference and returns the same integers but sorted smallest to biggest.
** smallSort() will sort correctly for all postive, negative, and zero integers even if two are equal.
********************************************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


// Function Prototype.
void smallSort(int &, int &, int &);

int main() {
	int a;	// first value to be sorted.
	int b;	// second value to be sorted.
	int c;	// third value to be sorted.

	cout << "Please enter three integers for sorting." << endl;
	cin >> a >> b >> c;

	smallSort(a, b, c);

	cout << a << ", " << b << ", " << c << endl;
	return 0;
}


/**********************************************************************************************************
** Description: Function smallSort() accepts a three int parameters by reference, sorts them, and returns
** them to the where smallSort() was called from. Function will sort correctly even if two inputs are equal.
***********************************************************************************************************/
void smallSort(int &a, int &b, int &c) {
	int tempA;	// Temporary holding variable for lowest number.
	int tempB;	// Temporary holding variable for middle number.
	int tempC;	// Temporary holding variable for highest number.

	// if else for determining lowest number.
	if ((a <= b) && (a <= c)) {
		tempA = a;
	}
	else if ((b <= a) && (b <= c)) {
		tempA = b;
	}
	else {
		tempA = c;
	}

	// if else for determining highest number.
	if ((a >= b) && (a >= c)) {
		tempC = a;
	}
	else if ((b >= a) && (b >= c)) {
		tempC = b;
	}
	else {
		tempC = c;
	}
	
	// if else to determine middle number.
	if (((a <= b) && (a >= c)) || ((a >= b) && (a <= c))) {
		tempB = a;
	}
	else if (((b <= a) && (b >= c)) || ((b >= a) && (b <= c))) {
		tempB = b;
	}
	else {
		tempB = c;
	}

	//...and finally we assign the sorted temp values to our reference variables.
	a = tempA;
	b = tempB;
	c = tempC;

	// No return statement!
}