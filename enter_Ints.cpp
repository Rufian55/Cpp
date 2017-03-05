#include <iostream>
using std::cout;
using std::cin;

int main() {
	cout << "Enter any int within +/- INT_MAX. Non integers will result in something bad.\n";
	for (int n; cin >> n;)
		cout << "Thank you for entering " << n << '\n';
	cout << "Something bad!\n";
	return 0;
}