#include <string>
#include<iostream>
using std::cin;
using std::cout;

int main() {

	int answer1 = 0;
	cout << "An int Question?\n"
		<< "1. Yes.\n"
		<< "2. No.\n";
	while (!(cin >> answer1) || answer1 < 1 || answer1 > 2) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input Error!\n"
			<< "A Question?\n"
			<< "1. Yes.\n"
			<< "2. No!\n";
	}
	cout << "The int answer is " <<  answer1 << "\n\n";


	char answer2 = 'X';
	cout << "A char Question?\n"
		<< "A. Yes.\n"
		<< "B. No.\n";
	while (!(cin >> answer2) || !isalpha(answer2) || answer2 != 'A' && answer2 != 'B') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input Error!\n"
			<< "A Question?\n"
			<< "A. Yes.\n"
			<< "B. No!\n";
	}
	cout << "The char answer is " << answer2 << "\n\n";


	std::string answer3 = "";
	cout << "A string Question?\n"
		<< "Yes.\n"
		<< "No.\n";
	while (!(cin >> answer3) || answer3 != "Yes" && answer3 != "No") {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input Error!\n"
			<< "A Question?\n"
			<< "Yes.\n"
			<< "No.\n";
	}
	cout << "The string answer is " << answer3 << "\n\n";
}