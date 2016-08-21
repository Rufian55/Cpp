/****************************************************************************
** Author: Chris Kearns
** Date: 10/14/2015
** Description: Script that returns min / max values for a 
** user inputted a) number of integer values and then b) the actual integer
** values, the amount of inputted values being essentially unlimited.
****************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int  numberOfValues,	// User inputted number of integers to be inputted.
		value,		// User inputted actual integer values to be "min-maxed".
		min = 0,	// Resulting minimimum value.
		max = 0;	// Resulting maximum value.

	do {
		cout << "How many integers would you like to enter?" << endl;
		cin >> numberOfValues;
		if (numberOfValues < 1) {
			do {
				cout << "Number of values must be an integer greater than 0. How many integers would you like to enter?" << endl;
				cin >> numberOfValues;
			} while (numberOfValues < 1);

			cout << "Please enter " << numberOfValues << " integers." << endl;

		} else {
			cout << "Please enter " << numberOfValues << " integers." << endl;
		}

	} while (numberOfValues < 1);

	cin >> value;
	min = value;
	max = value;

	for (int i = 1; i < numberOfValues; i++) {
		cin >> value;
		if (value <= min) {
			min = value;
		}
		else if (value >= max) {
			max = value;
		}
	}

	cout << "min: " << min << endl << "max: " << max << endl;
	return 0;
}
