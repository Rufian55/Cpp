#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;

int main() {
	ifstream f("red.jpg", std::ios::binary);
	vector<uint8_t> v{ std::istreambuf_iterator<char>{f}, {} };
	cout << "Read complete, got " << v.size() << " bytes\n";

	return 0;
}