/****************************************************************************************************
** Author: Chris Kearns
** Date: 10/14/2015
** Description: Number Guessing game prompts the user for an integer that the player
** will try to guess. If the player's guess is higher than the target number, the program displays
** "too high". If the player's guess is lower than the target number, the program displays "too low".
** The program uses a loop that repeats until the player correctly guesses the number, following
** which, the program prints how many guesses it took. 
****************************************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
uisng std::endl;

int main() {

	int theNumber;		// The number entered by the user for the player to guess.
	int	guess;		// The player's guess.
	int counter = 0;	// The running total of guesses, initialized to zero.

	cout << "Enter the number for the player to guess." << endl;
	cin >> theNumber;
	cout << "Enter your guess." << endl;
	cin >> guess;

	do {
		if (guess > theNumber) {
			counter++;
			cout << "Too high - try again." << endl;
			cin >> guess;
		}
		else if (guess < theNumber) {
			counter++;
			cout << "Too low - try again." << endl;
			cin >> guess;
		}
	} while (guess != theNumber);

	if (guess == theNumber) {
		counter++;
		cout << "You guessed it in " << counter << " tries." << endl;
	}
	return 0;
}