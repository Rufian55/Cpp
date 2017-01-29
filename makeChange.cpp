/******************************************************************************
* makeChange.cpp outputs minimum number of coins to make a given change input
* as argv[1]. Usage is makeChange {int currency2Return}
* Compile: g++ makeChange.cpp -o makeChange -g -Wall
* [1]
*******************************************************************************/
#include <climits>
#include <cstdlib>
#include <iostream>
using std::cout;

// Prototypes.
int minCoins(int coins[], int m, int V);

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Usage: makeChange {int currency2Return}\n";
		exit(1);
	}
	int coins[] = { 50, 20, 10, 5, 2, 1 };		// U.K.
	int m = sizeof(coins) / sizeof(coins[0]);	// m is size of coins array (# of diff. coins)
	int V = atoi(argv[1]);
	cout << "Minimum coins required is " << minCoins(coins, m, V) << '\n';
	return 0;
}


int minCoins(int coins[], int m, int V) {
	// table[i] will  store the minimum number of coins
	// required for i value, therefore table[V] is result.
	int table[V + 1];

	// Base case (If given value V is 0)
	table[0] = 0;

	// Initialize all table values EXCEPT table[0] as Infinite.
	for (int i = 1; i <= V; i++)
		table[i] = INT_MAX;

	// Compute min coins required for all values from 1 to V.
	for (int i = 1; i <= V; i++) {
		// Process all coins smaller than i.
		for (int j = 0; j < m; j++) {
			if (coins[j] <= i) {
				int sub_res = table[i - coins[j]];
				if (sub_res != INT_MAX && sub_res + 1 < table[i]) {
					table[i] = sub_res + 1;
				}
			}
		}
	}
	return table[V];
}

// [1] Adapted from http://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/