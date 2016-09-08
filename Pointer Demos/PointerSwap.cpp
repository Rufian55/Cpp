/* Demonstrates passing constant pointers to alter argument variables.*/
#include <iostream>
using std::cout;

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

int main() {
	int myScore = 150;
	int yourScore = 1000;
	cout << "Original values\n";
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n\n";
	cout << "Calling badSwap()\n";
	badSwap(myScore, yourScore);
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n\n";
	cout << "Calling goodSwap()\n";
	goodSwap(&myScore, &yourScore);
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n";
	return 0;
}

void badSwap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void goodSwap(int* const pX, int* const pY) {
	// Store value pointed to by pX in temp.
	int temp = *pX;
	// Store value pointed to by pY in address pointed to by pX.
	*pX = *pY;
	// Store value originally pointed to by pX in address pointed to by pY.
	*pY = temp;
}