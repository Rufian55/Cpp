/****************************************************************************************
** Program Filename: Pointers.cpp
** Author: Chris Kearns
** Date: 1/19/2016
** Description: Source file: Pointers.cpp.
** Input: None
** Output: cout's various pointer usage demonstrations.
*****************************************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {

	cout << endl << "POINTERS TO VARIABLES and POINTERS TO POINTERS:" << endl << endl;

	// Declare a variable called var.
	int var = 99;
	cout << "1. variable 'var' = " << var << endl << endl;

	// Declare a pointer to var with " int *ptr = &var ".
	int *ptr = &var;

	// cout the memory location of var (what the ptr pointer points to) with " cout << ptr ".
	cout << "2. Pointer 'ptr' = " << ptr << endl << endl;

	// cout the variable pointed to by ptr by dereferencing ptr with " *ptr ". 
	cout << "3. Dereferencing 'ptr' with ' *ptr ' yields the value stored in 'var':" << endl
		 << "\tso, ' cout << *ptr ' = " << *ptr << endl << endl;

	// Declare a pointer to a pointer.
	cout << "Now we declare a pointer to a pointer, in this case a pointer to ptr with" << endl
		 << "\t' **ptr2ptr = &ptr '.  Note that one splat or &var is incorrect!" << endl << endl;
	int **ptr2ptr = &ptr;

	// cout the ptr2ptr memory address.
	cout << "4. Using ' cout << ptr2ptr ' we see the memory address" << endl
		 << "\tof ptr2ptr = " << ptr2ptr << endl << endl;

	// cout ptr memory address by dereferencing ptr2ptr.
	cout << "5. Using ' *ptr2ptr ' to deference the pointer 'ptr2ptr' yields"<< endl
		 << "\tthe memory address for 'ptr' = " << *ptr2ptr << endl
		 << "\tNotice it's the same as #2." << endl
		 << "\tAlso notice that this ' *ptr2ptr ' is the pointer that has no name." << endl << endl;

	// cout var by double dereferencing ptr2ptr.
	cout << "6. Double dereferencing ptr2ptr with ' **ptr2ptr ' yields" << endl
		 << "\tthe value of var = " << **ptr2ptr << endl
		 << "\tNotice its the same as var!" << endl;

	
	cout << endl << "POINTERS TO 1D and 2D ARRAYS and ACCESSING ARRAYS WITH POINTERS:" << endl << endl;

	// Declare a static array named anArray.
	cout << "We declare a 3 member static array with ' int anArray[3] = {2, 4, 6}; '" << endl << endl;
	int anArray[3] = {2, 4, 6};

	// cout the static array using bracket notation.
	cout << "7. Using a for loop to cout each anArray[i] yields" << endl;
	for (int i = 0; i < 3; i++)
		cout << "\t anArray[" << i << "] = " << anArray[i] << endl;
	cout << endl;

	cout << "8. Simply cout 'anArray' yields anArray[0] memory address = " << anArray << endl << endl;

	cout << "9. Dereferencing anArray with ' *anArray ' yields the value at anArray[0] = " << *anArray << endl << endl;

	cout << "10. Dereferencing anArray with pointer addition gets you the other 2 values" << endl
		 << "\tUsing ' *(anArray + 1) ' yields the value at anArray[1] = " << *(anArray + 1) << endl
		 << "\tUsing ' *(anArray + 2) ' yields the value at anArray[1] = " << *(anArray + 2) << endl << endl;

	cout << "11. We can cout the array in a for loop with pointer addition." << endl
		 << "\tusing ' *(anArray + i) ' in place of ' anArray[i] subscript notation.'" << endl;

	for (int i = 0; i < 3; i++)
		cout << "\t*(anArray + " << i << ") = " << *(anArray + i) << endl;
	cout << endl;
	

	cout << endl << "POINTERS TO 2D ARRAYS and ACCESSING 2D ARRAYS WITH POINTERS:" << endl << endl;

	// Declare a 2 x 3 array called a2Darray.
	cout << "12. We declare a 2x3 two dimenisional 'a2Darray' with:" << endl
		 <<"\t' int a2Darray[2][3] = { 11, 12, 13, 21, 22, 23 }; '" << endl << endl;
	
	int a2Darray[2][3] = { 11, 12, 13, 21, 22, 23 };

	// cout a2Darray using subscript notation.
	cout << "...and we cout a2Darray using subscript notation using a nested loop" << endl
		<< "\tand ' cout << a2Darray[i][j]; '" << endl << endl;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << "\ta2Darray[" << i << "][" << j << "] = " << a2Darray[i][j] << endl;
	}
	cout << endl;

	// cout a2Darray memory addresses using pointer notation and pointer arithmetic.
	cout << "13. We cout a2Darray memory addresses by dereferencing in a nested loop" << endl
		 << "\tand leveraging pointer aritmetic with '(*(a2Darray + i) + j)'" << endl
		 << "\tThis is a2Darray's individual memory addresses, each a pointer" << endl
		 << "\tto the value contained at that memory address." << endl << endl;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << "\tThe memory address of (*(a2Darray + " << i << ") + " << j << ") = " << (*(a2Darray + i) + j) << endl;
	}
	cout << endl;

	// cout a2Darray values using pointer notation and pointer arithmetic.
	cout << "14. We cout the a2Darray values by dereferencing each dereferenced" << endl
		 << "\ta2Darray memory address and pointer arithmetic '*(*(a2Darray + i) + j)'" << endl
		 << "\tjust like you did with the individual pointer 'ptr' in #3 above." << endl << endl;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << "\tThe value at *(*(a2Darray + " << i << ") + " << j << ") = " << *(*(a2Darray + i) + j) << endl;
	}
	cout << endl;

	
	cout << endl << "POINTERS, NODES, and LINKED LISTS:" << endl << endl;
	
	// A simple three node linked list of struct's using object pointer operator notation.

	// We declare a struct class called LinkedNode containing int someVar and a pointer 'next'.
	struct LinkedNode {
		int someVar;			// The data portion of the struct.
		LinkedNode *next;		// The pointer to the next node in the list.
	};

	LinkedNode *head;			// Declare a LinkedNode pointer called head.
	head = new LinkedNode;			// Instantiate head as a LinkedNode object.
	head->someVar = 666;			// Set this node's (head) someVar to 666 using the pointer operator.
	head->next = NULL;			// Set the next pointer to NULL.

	LinkedNode *node2 = new LinkedNode;	// Declare another LinkedNode pointer called node2 and instantiate node2 as a LinkedNode in one line.
	node2->someVar = 777;			// Set this node's (node2) someVar to 777 using the pointer operator.
	node2->next = NULL;			// Set this node's (node2) next pointer to NULL.
	head->next = node2;			// Set the one up in the list node's (head) next pointer to this node (node2). 

	LinkedNode *node3 = new LinkedNode;	// Declare another LinkedNode pointer called node3 and instantiate node3 as a LinkedNode in one line.
	node3->someVar = 888;			// Set this nodes (node3) someVar to 888 using the pointer operator.
	node3->next = NULL;			// Set this nodes (node3) next pointer to NULL.
	node2->next = node3;			// Set the one up in the list node's (node2) next pointer to this node (node3). 

	// cout the list using the preveious nodes pointer the node being queried.
	cout << "The 'head' node contains int someVar = " << head->someVar << endl;
	cout << "The next node, called 'node2', has int someVar = " << head->next->someVar << endl;
	cout << "The last node, called 'node3', has int someVar = " << node2->next->someVar << endl;
	cout << "The value of pointer 'next' = " << next << endl;
	cout << "The memory address pointer 'next' contains = " << *next << endl;

	cout << endl;
}
