/****************************************************************************
** Author: Chris Kearns
** Date: 10/8/2015
** Description:  Script that converts user inputted cents value
** and outputs the same amount as the smallest total number of coins.
****************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	// Assume the 50-cent piece is no longer in circulation.
	int quarters, dimes, nickels, pennies,
	    userAmount,		// Holds amount entered by user.
	    looseChange;	// Remaining cents to be processed as program executes.

	cout << "Please enter an amount in cents, no decimal, less than a dollar." << endl;

	cin >> userAmount;

	quarters = userAmount / 25;
	looseChange = userAmount % 25;
	dimes = looseChange / 10;
	looseChange %= 10;
	nickels = looseChange / 5;
	pennies = looseChange %= 5;

	cout << "Your change will be:" << endl;

	//Output the resulting number of coins, highest currency to lowest, formatted as required.
	cout << "Quarters: " << quarters << endl << "Dimes: " << dimes << endl << "Nickels: " 
		<< nickels << endl << "Pennies: " << pennies << endl;
	
	return 0;
}
