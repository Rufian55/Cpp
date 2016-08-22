/****************************************************************************************
** Program Filename: ReadMatrix.cpp
** Author: Chris Kearns
** Date: 1/8/2016
** Description: Source file: ReadMatrix.cpp. Called by Main.cpp for prompting and reading
** in user inputted matrix variables.
** Input: Pointer to 2D Array, int (size of the square)
** Output: void, but note user prompts and read in to myArray.
****************************************************************************************/
#include "ReadMatrix.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/***************************************************************************************
** Function: readMatrix()
** Description: Prompts the user to fill a square matrix of size 2x2
** or 3x3.
** Parameters: Pointer to the 2D myArray and int user desired Matrix size.
** Pre-Conditions: Requires pointer to a 3x3 array and an int = 4 or 9.
** Post-Conditions: void but note iostream outputs.
***************************************************************************************/

void readMatrix(int (*myArray)[3], const int var) {
	// Read in user values for a 2x2 matrix.
	if (var == 4) {
		cout << "Please enter 4 integers for your Matrix starting with Row 1, Column 1." << endl;
		cin >> myArray[0][0];
		cout << "Thank you, now please enter the 2nd integer for Row 1, Column 2." << endl;
		cin >> myArray[0][1];
		cout << "Thank you, now enter the 3rd integer for Row 2, Column 1." << endl;
		cin >> myArray[1][0];
		cout << "...and finally, enter the 4th integer for Row 2, Column 2." << endl;
		cin >> myArray[1][1];
	}

	else {
		// Read in user values for a 3x3 matrix.
		if (var == 9) {
			cout << "Please enter your 9 integers starting at Row 1, Column 1 " << endl
				 << "and ending at Row 3, Column 3." << endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cout << "Please enter an integer." << endl;
					cin >> myArray[i][j];
				}
			}
		}
	}
};
