// Compile with "g++ yourCPPfile.cpp -o yourExecName -g -Wall"
#include <iostream>
#include <iomanip>
#include <fstream>
using std::ifstream;
#include <cstdio>
using std::cout;

int main() {
	ifstream inputFile;
	int count, value, negative, positive, zero;
	count = negative = positive = zero = 0;
	double negPerc, posPerc, zeroPerc;

	inputFile.open("input.txt");

	if (!inputFile.fail()) {
		while (inputFile >> value) {
			count++;
			if (value < 0)
				negative++;
			if (value == 0)
				zero++;
			if (value > 0)
				positive++;
		}
	}
	else {
		cout << "\nError, unable to open input file " << inputFile << "!\n";
	}

	cout << std::setprecision(1);

	// Troubleshooting!!
	cout << negative << "\n";
	cout << positive << "\n";
	cout << zero << "\n";
	cout << count << "\n";

	// Calculations.
	negPerc = (negative * 100.0 / count);
	posPerc = (positive * 100.0 / count);
	zeroPerc = (zero * 100.0 / count);

	// your desired result...
	cout << "There were " << std::fixed << negPerc << "% negative numbers." << "\n";
	cout << "There were " << std::fixed << zeroPerc << "% numbers equal to zero." << "\n";
	cout << "There were " << std::fixed << posPerc << "% numbers greater than zero." << "\n";
	return 0;
}