#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::cout;
using std::cin;

int main() {
	int choice, intBuffer, subtotalGrades, countGrades, average, highGrade, lowGrade = 100;
	choice = intBuffer = subtotalGrades = countGrades = average = highGrade = 0;
	std::string nameBuffer, studentHigh, studentLow;

	cout << "\tStudent Grade Book Info Program....\n";
	cout << "\tPlease Select an Option: (1 or 2) \n" << "\n"
		<< "\t1. Review Grades"
		<< "\n\t2. Quit"
		<< "\n\tChoose: ";
	cin >> choice;
	if (choice == 2) {
		return 0;
	}
	else {
		std::ifstream gFile("gradeBook.txt", std::ios::in);
		if (!gFile) {
			cout << "\tError... Could open gradeBook.txt\n";
			return 1;
		}
		getline(gFile, nameBuffer);
		gFile >> intBuffer;
		while (gFile) {
			gFile.ignore();
			getline(gFile, nameBuffer);
			gFile >> intBuffer;
			if (intBuffer > highGrade) {
				highGrade = intBuffer;
				studentHigh = nameBuffer;
			}
			else if (intBuffer < lowGrade) {
				lowGrade = intBuffer;
				studentLow = nameBuffer;
			}
			subtotalGrades += intBuffer;
			countGrades++;
		}
		gFile.close();
	}
	average = subtotalGrades / countGrades;

	// Report section.
	cout << "\t" << std::setw(20) << "Student" << std::setw(30) << "Grade" << "\n";
	cout << "\t" << std::setw(20) << studentHigh << std::setw(30) << highGrade << "\n";
	cout << "\t" << std::setw(20) << studentLow << std::setw(30) << lowGrade << "\n";
	cout << "\t" << std::setw(20) << "Average" << std::setw(30) << average << "\n";

	return 0;
}
