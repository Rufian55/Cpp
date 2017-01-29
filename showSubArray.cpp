/******************************************************************************
* Program showSubArray prints to stdout the subarray of arrN[] that totals to
* the given maxSum.  Interesting use of a C++ STL unordered_map. 
* Compile: g++ showSubArray.cpp -o showSub -std=c++0x -g -Wall
* Note need for minimum C++11 for this program to compile.
******************************************************************************/
#include <unordered_map>
#include <iostream>
using std::cout;

// Prototypes.
void showSubArray(int arr[], int n, int maxSum);

int main() {

	int arr1[] = { 1, 4, -9, 8, 1, 3, 3, 1, -1, -4, -6, 2, 8, 19, -10, -11 };
	int n = 16, maxSum = 34;
	showSubArray(arr1, n, maxSum);

	int arr2[] = { 2, 9, 8, 6, 5, -11, 9, -11, 7, 5, -1, -8, -3, 7, -2 };
	n = 15, maxSum = 30;
	showSubArray(arr2, n, maxSum);

	int arr3[] = { 10, -11, -1, -9, 33, -45, 23, 24, -1, -7, -8, 19 };
	n = 12, maxSum = 50;
	showSubArray(arr3, n, maxSum);

	int arr4[] = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };
	n = 10, maxSum = 187;
	showSubArray(arr4, n, maxSum);

	int arr5[] = { 3, 2, 1, 1, -8, 1, 1, 2, 3 };
	n = 9, maxSum = 7;
	showSubArray(arr5, n, maxSum);

	int arr6[] = { 12, 99, 99, -99, -27, 0, 0, 0, -3, 10 };
	n = 10, maxSum = 210;
	showSubArray(arr6, n, maxSum);

	int arr7[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	n = 9, maxSum = 7; // maxSum is actually 7, tests "Subarray not found!"
	showSubArray(arr7, n, maxSum);

	return 0;
}


void showSubArray(int arr[], int n, int maxSum) {
	std::unordered_map<int, int> aMap;
	int accumulator = 0;

	for (int i = 0; i < n; i++) {
		accumulator += arr[i];

		if (accumulator == maxSum) {
			for (int j = 0; j <= i; j++) {
				cout << arr[j];
				cout << " ";
			}
			cout << '\n';
			return;
		}

		if (aMap.find(accumulator - maxSum) != aMap.end()) {
			for (int j = aMap[accumulator - maxSum] + 1; j <= i; j++) {
				cout << arr[j];
				cout << " ";
			}
			cout << '\n';
			return;
		}

		aMap[accumulator] = i;
	}

	cout << "Subarray not found!\n";
}