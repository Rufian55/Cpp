/****************************************************************************************
** Program Filename: Main.cpp
** Author: Chris Kearns
** Date: 1/8/2016
** Description: Main Program file.
** Input: User input mandatory, readMatrix(), determinant().
** Output: Outputs formatted user entered matrix and calculated determinant.
****************************************************************************************/
#include "ReadMatrix.hpp"
#include "Determinant.hpp"
#include <cmath>
using std::sqrt;
#include <iomanip>
using std::setw;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	// Initial user prompt for desired matrix size.
	int var;
	cout << "Enter 4 for a 2x2 array, 9 for a 3x3 array, or 0 to quit." << endl;
	cin >> var;

	// User input validation.
	while ((var != 4) && (var != 9) && (var != 0)) {
		cout << "Error, please enter 4 for a 2x2 array, 9 for a 3x3 array, or 0 to quit." << endl;
		cin >> var;
		// Exit while loop if user inputs 0 for quit.
		if (var == 0)
			return 0;
	}

	// Program exit if user has input 0 for quit.
	if (var == 0)
		return 0;

	// Declare a static 3x3 array (used by 2x2 matrix also as opposed to dynamic array method)
	int myArray[3][3];

	// Read in user inputted matrix values.
	readMatrix(myArray, var);

	// Prep for outputing formatted matrix (myArray) contents.
	int rows, cols;
	rows = cols = sqrt(var);
	cout << endl << "The matrix values you entered are:" << endl << endl;

	// Nested loop for displaying matrix (myArray) values.
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(10) << myArray[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// Get and output matrix's (myArray) determinant value.
	int det = determinant(myArray, var);
	cout << "Your matrix determinant is " << det << endl << endl;

}
