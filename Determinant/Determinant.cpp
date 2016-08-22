/****************************************************************************************
** Program Filename: Determinant.cpp
** Author: Chris Kearns (CS-162-400 W2016)
** Date: 1/8/2016
** Description: Source file: Determinant.cpp.
** Input: Determinant.hpp and Main.cpp
** Output: returns dtr int value to Main.cpp
*****************************************************************************************/
#include "Determinant.hpp"

/***************************************************************************************
** Function: determinant()
** Description: Returns int value of the determinant of the input parameter array (the 
** matrix). See notes below or www.mathsisfun.com/algebra/matrix-determinant.html for a
** conceptual discussion on how determinants are calculated.
** Parameters: 2D Array, int (size of the square)
** Pre-Conditions: myArray[][3] and var (size of matrix) must contain valid integers.
** Post-Conditions: No changes made to myArray[][3] or var.
****************************************************************************************/

int determinant(const int myArray[][3], const int var) {
	int dtr;

	// Calculate determinant in 2x2 matrix.
	if (var == 4){
	dtr = (myArray[0][0] * myArray[1][1]) - (myArray[0][1] * myArray[1][0]);
	return dtr;
	}

	else {
		// Calculate determinant in 3x3 matrix.
		if (var == 9) {
			int a = myArray[0][0] * ((myArray[1][1] * myArray[2][2]) - (myArray[1][2] * myArray[2][1]));

			int b = myArray[0][1] * ((myArray[1][0] * myArray[2][2]) - (myArray[1][2] * myArray[2][0]));

			int c = myArray[0][2] * ((myArray[1][0] * myArray[2][1]) - (myArray[1][1] * myArray[2][0]));

			dtr = a - b + c;
			return dtr;
		}
	}
};

/*
Notes on calculating the determinant of a matrix.
Array subscript syntax is myArray[row][column].

2x2
	  0 1
	0|a b|
	1|c d|

|dtr| = ad - bc

3x3
	  0 1 2
	0|a b c|
	1|d e f|
	2|g h i|

|dtr| = a(ei-fh) - b(di-fg) + c(dh-eg)

*/