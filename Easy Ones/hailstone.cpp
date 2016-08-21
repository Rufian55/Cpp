/**********************************************************************************************************
** Author: Chris Kearns
** Date: 10/21/2015

** Description: function hailstone() to be included in other programs as needed and accepts 
** a positive integer passed by value. If that integer is even, then it is divided by two to get the next
** integer in the sequence, but if it is odd, then it is multiplied by three and increased by one to get
** the next integer in the sequence. The function is halted as soon as "1" is reached.  hailstone()
** returns the number of steps it takes to reach 1, not counting the first step. If 1 is input, then "0"
** will be returned. Negative integers will be converted to their additive inverse. Zero is converted to 1.
**********************************************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>	// abs().

// Function Prototype.
int hailstone(int);

int main() {
	int input;	// Holder varaible for integer input by user.
	int result;	// Our returned value from hailstone. 

	cout << "Please enter a positive integer for \"hailstone\"." << endl;
	cin >> input;

	result = hailstone(input);
	cout << "Number of steps to reach 1 was: " << result << endl;
	return 0;
}


/**********************************************************************************************************
** Description: Function hailstone() to be included in other programs as needed and accepts a positive
** integer passed by value.  If that integer is even, then it is divided by two to get the next
** integer in the sequence, but if it is odd, then it is multiplied by three and increased by one to get
** the next integer in the sequence. The function is halted as soon as "1" is reached (via a while loop 
** and hailstone() then returns the number of steps it takes to reach 1, not counting the first step. If 1
** is input, then "0" will be returned. If negative integers are input, they will be converted to their
** additive inverse. If zero is inputted it is converted to 1 and returns 0. 
***********************************************************************************************************/
int hailstone(int anInput) {
	int result = 0;// The resulting number of steps it takes hailstone to reach 1.

	double temp = anInput;
	temp = std::abs(temp);
	anInput = temp;

	if ((anInput == 0) || (anInput == 1)) {
		result = 0;
	}
	else {
		while (anInput != 1) {
			if (anInput %2 == 0) {
				anInput /= 2;
				result++;
			}
			else {
				anInput = (anInput * 3) + 1;
				result++;
			}
		}
	}
	return result;
}