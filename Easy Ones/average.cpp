/****************************************************************************
** Author: Chris Kearns
** Date: 10/8/2015
** Description: Script that prompts user for 5 numbers,
** calculates the average, and outputs this average to the user console.
****************************************************************************/
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main() {
	float num_1,
		 num_2,
		 num_3,
		 num_4,
		 num_5,
		 averageNum;

	cout << "Please enter five ints, floats, or doubles." << endl;
	
	cin >> num_1 >> num_2 >> num_3 >> num_4 >> num_5;

	averageNum = (num_1 + num_2 + num_3 + num_4 + num_5) / 5;

	cout << std::fixed << std::setprecision(2);

	cout << "The numbers you entered were:\n";

	cout << num_1 << endl << num_2 << endl << num_3 << endl << num_4 << endl << num_5 << endl;

	cout << "The average of those numbers is:" << endl;

	cout << averageNum << endl;

	return 0;
}