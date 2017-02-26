#include <iostream>
using std::cout;
#include <random>

// Prototypes.
void MersenneTwister(int n);
void MersenneTwister_2(int n);

int main() {
	MersenneTwister(64);
	MersenneTwister_2(64);
	return 0;
}

void MersenneTwister(int n) {
	std::mt19937 e(std::random_device{}());
	std::bernoulli_distribution d;

	for (int i = 0; i < n; i++)
		cout << d(e);
	cout << '\n';
}

void MersenneTwister_2(int n) {
	std::random_device r;
	std::seed_seq s{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 e(s);
	std::bernoulli_distribution d;

	for (int i = 0; i < n; i++)
		cout << d(e);
	cout << '\n';
}
