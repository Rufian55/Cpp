/*****************************************************************************
* cutRod.cpp is the classic cutRod algorithm utilizing an extended method.
* The naive, bottom up & top down solutions are written but not used.
* Compile with g++ cutRod.c -o cutRod -g -Wall
* Adapted from Intro. to Algorithms (3rd Ed.), CLRS, Chapter 15.1
*****************************************************************************/
#include <algorithm>
using std::max;
#include <cstring>
#include <iostream>
using std::cout;
using std::cin;

#define MAXSIZE 1000

// Prototypes.
void init(int *price, int *revenue);
int cutRod(int n, int *price);
int topDownCutRod(int n, int *revenue, int *price);
int buttomUpCutRod(int n, int *revenue, int *price);
int extendedButtomUpCutRod(int n, int *revenue, int *price, int *size);
void printCutRodSolution(int n, int *size);

int main() {
	int price[11];
	int revenue[MAXSIZE];
	int size[MAXSIZE];

	init(price, revenue);
	int n;
	cout << "Enter length of rod to be cut: ";
	cin >> n;
	cout << "Maximized Revenue is $" << extendedButtomUpCutRod(n, revenue, price, size) << "\n";
	printCutRodSolution(n, size);
	return 0;
}

// Initializer for prices and optimal solutions:
void init(int *price, int *revenue) {
	memset(revenue, -1, MAXSIZE); // Set all elements of revenue to -1.
	revenue[0] = 0;
	price[0] = 0;
	price[1] = 1;
	price[2] = 3;
	price[3] = 8;
	price[4] = 10;
	price[5] = 10;
	price[6] = 17;
	price[7] = 18;
	price[8] = 20;
	price[9] = 22;
	price[10] = 28;
}

// Naive recursive O(2^n) solution.
int cutRod(int n, int *price) {
	int q = 0;
	for (int i = 1; i <= n; i++) {
		q = max(q, price[i] + cutRod(n - i, price));
	}
	return q;
}

// Top-down recursive solution O(2^n).
int topDownCutRod(int n, int *revenue, int *price) {
	if (revenue[n] != -1)
		return revenue[n];
	int q = 0;
	for (int i = 1; i <= n; ++i)
		q = max(q, price[i] + topDownCutRod(n - i, revenue, price));
	return revenue[n] = q;
}

// Bottom-up solution Θ(n^2).
int buttomUpCutRod(int n, int *revenue, int *price) {
	if (revenue[n] != -1)
		return revenue[n];
	for (int j = 1; j <= n; ++j) {
		int q = 0;
		for (int i = 1; i <= j; ++i)
			q = max(q, price[i] + revenue[j - i]);
		revenue[j] = q;
	}
	return revenue[n];
}

// Iterative bottom-up solution for best price and "required cuts" O(n^2).
int extendedButtomUpCutRod(int n, int *revenue, int *price, int *size) {
	if (revenue[n] != -1)
		return revenue[n];
	for (int j = 1; j <= n; j++) {
		int q = 0;
		for (int i = 1; i <= j; i++)
			if (q < price[i] + revenue[j - i]) {
				q = price[i] + revenue[j - i];
				size[j] = i;
			}
		revenue[j] = q;
	}
	return revenue[n];
}

// Prints extended method's output.
void printCutRodSolution(int n, int *size) {
	cout << "From the rod of length " << n << ", cut these sizes: ";
	do {
		cout << size[n] << " ";
	}
	while ((n -= size[n]) > 0);
	cout << "\n";
}
