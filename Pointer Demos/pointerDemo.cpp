/******************************************************************************************************
** Basic pointer usage in C++
*******************************************************************************************************/
#include <iostream>
using std::cout;
using std::endl;

int main() {
	int x = 10;

	// creates a pointer and stores the address of x
	int *ptrx = &x;

	cout << "the value of x is: " << x << endl;			// outputs 10
	cout << "the address of x is: " << &x << endl;		// outputs hex memory address of "10"

	cout << endl << endl;

	// outputs hex memory address of "10"
	cout << "1st level pointer storage holds: " << ptrx << endl;

	// outputs "10" as ptrx is dereferenced (outputs what's in the container ptrx is pointing to).
	cout << "1st level dereferenced to original x value: " << *ptrx << endl;	

	// outputs ptrx's hex memory address.
	cout << "1st level pointer storage address: " << &ptrx << endl;

	cout << endl << endl;

	// creates a pointer to a pointer and stores the address
	// of the first pointer
	int **ptrptrx = &ptrx;

	// outputs the 1st level pointers hex memory address. 
	cout << "2nd layer pointer storage holds: " << ptrptrx << endl;

	// outputs the 1st level pointers storage container contents (namely, the contents of ptrx).
	cout << "2nd layer dereferenced once: " << *ptrptrx << endl;

	// outputs 10, (the contents of the pointer ptrx that points to ptrx that points to 10)
	cout << "2nd layer dereferenced twice: " << **ptrptrx << endl;

	// outputs the memory addrss of the 2nd level pointer.
	cout << "2nd layer pointer storage address: " << &ptrptrx << endl;

	cout << endl << "Heck... let's go three layers!!!" << endl << endl;

	// creates a pointer to a pointer to a pointer 
	// and stores the address of the second pointer which stores the address of
	// the first pointer which stores the address of x .... WHEW!
	// ptrptrptrx ===> ptrptrx ===> ptrx ===> x
	int ***ptrptrptrx = &ptrptrx;

	cout << "3rd layer pointer storage holds: " << ptrptrptrx << endl;
	cout << "3rd layer dereferenced once: " << *ptrptrptrx << endl;
	cout << "3rd layer dereferenced twice: " << **ptrptrptrx << endl;
	cout << "3rd layer dereferenced three times: " << ***ptrptrptrx << endl;
	cout << "3rd layer pointer storage address: " << &ptrptrptrx << endl;


	cout << endl << "...and now some pointer arithmetic...\n"
	const int SIZE = 3;
	int arr[SIZE] = { 1,2,3 };
	int *pInt;
	pInt = arr;

	//We want to display the values in the array so we use either of the below.
	cout << "1. " << *(arr + 0) << endl;
	cout << "2. " << *(arr + 1) << endl;
	cout << "3. " << *(pInt + 0) << endl;
	cout << "4. " << *(pInt + 1) << endl;
	cout << "Works both ways...\n";
	cout << "5. " << *(arr + 2) << endl;
	cout << "6. " << *(arr + 1) << endl;
	cout << "7. " << *(pInt + 2) << endl;
	cout << "8. " << *(pInt + 1) << endl;

	return 0;
}