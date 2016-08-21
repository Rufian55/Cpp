/****************************************************************************************************
** Author: Chris Kearns
** Date: 10/14/2015
** Description: Program that prompts the user for the name of a file and then tries to
** open it. If the input file is there and can be opened, the program reads the list of integers
** in the file, then adds together all the integers in the file, opens an output file called sum.txt,
** and writes the sum to that file, and finally closes both files. The file used for input testing is
** input.txt, though any named file in the proper format will work.
****************************************************************************************************/
#include <iostream>
#include <fstream> 
#include <string>
using std::cin;
using std::cout;
using std::endl;

int main() {
	std::string filename;		// Our users file name will be held as a string called "filename".
	std::ifstream inputFile;		// File stream object.
	std::ofstream outputFile;	// File stream object.
	int holder = 0;			// Used to read integers as they are read and test for EOF condition.
	int sumVar = 0;			// USed to sum up the holder variables as they are read.

	cout << "Please enter the name and extension of the file to be read (for example: input.txt)." << endl;

	cin >> filename;

	inputFile.open(filename.c_str());

	if (inputFile) {
		while (inputFile >> holder) {
			sumVar += holder;
		}
		inputFile.close();// Closes the file once we are done readng it. 
	}

	else {
		cout << "Sorry, I could not access your input file." << endl;
	}
	
	outputFile.open("sum.txt");

	if (outputFile) {
		outputFile << sumVar << endl;
		outputFile.close();
	}

	return 0;
}