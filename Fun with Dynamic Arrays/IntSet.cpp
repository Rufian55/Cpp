/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/25/2015
** Description: IntSet.cpp is the IntSet class function implementation file and as such has the
** IntSet.hpp specification file included.
**********************************************************************************************************/
#include "IntSet.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

IntSet::IntSet(){
	sizeArray = 10;
	intSet = new int[sizeArray];
	numVals = 0;
}

IntSet::~IntSet() {
	delete[] intSet;
	intSet = 0;
}


/**********************************************************************************************************
**					function IntSet::size()
**
** Description: IntSet size function definition that accesses the numVals private variable and returns it.
** const set so testing in main can utilize it to print out arrays using size() as the test expression.
**********************************************************************************************************/
int IntSet::size() const {
	int count = numVals;
	return count;
}


/**********************************************************************************************************
**					function IntSet::isEmpty()
**
** Description: IntSet isEmpty function definition that checks to see if numVals has been incremented past
** it's initialization value of 0 or has been subsequently decremented back to 0.
**********************************************************************************************************/
bool IntSet::isEmpty() {	
	int count = numVals;
	if (count == 0)
		return true;
	else
		return false;
}


/**********************************************************************************************************
**					function IntSet::contains()
**
** Description: IntSet contains function definition that checks to see if the integer passed is contained
** in the inTset array and returns boolean as appropirate.
**********************************************************************************************************/
bool IntSet::contains(int anInt) const {
	int cont = 0;
	for (int i = 0; i < numVals; i++) {
		if (intSet[i] == anInt)
			cont = 1;
	}
	if (cont == 1) {
		return true;
	}
	else {
		return false;
	}
}


/**********************************************************************************************************
**					function IntSet::add()
**
** Description: IntSet add function definition that takes an int parameter, checks to see if int is already
** in the array, if so, does nothing, if not, adds the int in the next avaialable element container as 
** determined by our numVals var, also increments numVals to keep track of the number of elements in the
** array.  Note, if the array is full, that is numVals is not less than sizeArray, a new dynamic array twice 
** as large as the old array is created, the old arrays values are copied element by element, the old array
** is deleted, the intSet pointer is set to point to the new array, the int parameter is now added to the 
** new array in the next open position as per numVals, and finally, numVals is incremented.
**********************************************************************************************************/
void IntSet::add(int newInt) {
	if (contains(newInt) == false) {
		if (numVals < sizeArray) {
			intSet[numVals] = newInt;
			numVals++;
		}
		else {
			int sArr = sizeArray;
			sizeArray = sArr * 2;
		
			int *intSetx2;
			intSetx2 = new int[sizeArray];
			for (int i = 0; i < numVals; i++)
				intSetx2[i] = intSet[i];

			delete[] intSet;
			intSet = intSetx2;
			
			intSetx2[numVals] = newInt;
			numVals++;
						
		}
	}
}


/**********************************************************************************************************
**					function IntSet::remove()
**
** Description: IntSet remove function definition that takes an int parameter, checks to see if int is
** already in the array, if so, removes it, if not, does nothing.  To actually remove the int we loop 
** through the array, and when we find it, we set a flag var to the element number. Next we overwrite the
** flagged element and sequentially all subsequent elements with a loop. Finally, numVals is decremented. 
**********************************************************************************************************/
void IntSet::remove(int delInt) {
	if (contains(delInt) == true) {
		for (int i = 0; i < numVals; i++) {
			if (intSet[i] == delInt) {
				int flag = i;
				for (int j = flag; j < numVals; j++) {
					intSet[j] = intSet[(j + 1)];
				}
			}
		}
		numVals--;
	}
}


/**********************************************************************************************************
**					function IntSet::addAll()
**
** Description: IntSet addAll function definition that takes as an argument an IntSet object,
** accesses the argument object's array, and loops through it checking to see if each element is already in
** our targeted array.  If the argument object array element is not in our targeted array, we add it with
** add() function. The add() function takes care of numVal incrementing tasks. Note that argument is passed
** as a constant to preclude changing the argument object's array. Ex: setA.addAll(setB);
**********************************************************************************************************/
void IntSet::addAll(const IntSet& setB) {
	for (int i = 0; i < setB.size(); i++) {
		if (contains(setB.intSet[i]) == false) {
			add(setB.intSet[i]);
		}
	}
}


/**********************************************************************************************************
**					function IntSet::removeDifferent()
**
** Description: IntSet removeDifferent function definition that takes as an argument an IntSet object,
** accesses the argument object's array, and loops through it checking to see if each element is not in
** our targeted array.  If the argument object array element is not in our targeted array, we remove it with
** remove() function. The remove() function takes care of numVal decrementing tasks. Note that argument is
** passed as a constant to preclude changing the argument object's array. Ex: setC.removeDifferent(setD);
**********************************************************************************************************/
void IntSet::removeDifferent(const IntSet& setD) {
	for (int i = 0; i < size(); i++) {
		if (setD.contains(intSet[i]) == false) {
			remove(intSet[i]);
		}
		if (setD.contains(intSet[i]) == false) {
			remove(intSet[i]);
		}
	}
}


/**********************************************************************************************************
**					function IntSet::removeSame()
**
** Description: IntSet removeSame function definition that takes as an argument an IntSet object,
** accesses the argument object's array, and loops through it checking to see if each element is in
** our targeted array.  If the argument object array element is in our targeted array, we remove it with
** remove() function. The remove() function takes care of numVal decrementing tasks. Note that argument is
** passed as a constant to preclude changing the argument object's array. Ex: setE.removeDifferent(setF);
**********************************************************************************************************/
void IntSet::removeSame(const IntSet& setF) {
	for (int i = 0; i < size(); i++) {
		if (setF.contains(intSet[i]) == true) {
			remove(intSet[i]);
		}
		if (setF.contains(intSet[i]) == true) {
			remove(intSet[i]);
		}
	}
}


int IntSet::getIntSet(int i) {
	return intSet[i];
}

// TESTING SCRIPT BELOW
int main() {
	cout << "Start TEST 1" << endl;

	IntSet setA;
	cout << "***setA*****" << endl;
	cout << "setA is empty = " << setA.isEmpty() << endl;		// check to see if isEmpty() works.
	cout << "setA contains 1 = " << setA.contains(1) << endl;	// check to see if contains() works

	setA.add(0);
	setA.add(1);
	setA.add(2);
	setA.add(3);
	setA.add(4);
	setA.add(5);
	setA.add(6);
	setA.add(7);
	setA.add(8);
	setA.add(9);
	setA.add(10);
	setA.add(11);
	setA.add(11); // Should not get added to array.
	setA.add(12);
	setA.add(13);
	setA.add(14);
	setA.add(15);
	setA.add(16);
	setA.add(17);
	setA.add(18);
	setA.add(19);
	setA.add(20);
	setA.add(21);
	setA.add(22);
	setA.add(23);
	setA.add(24);

	setA.remove(0); // "0" should not be in setA array.

	for (int i = 0; i < setA.size(); i++) {
		cout << "element [" << i << "] = " << setA.getIntSet(i) << endl;
	}

	cout << "setA is empty = " << setA.isEmpty() << endl;			// check to see if isEmpty() works.
	cout << "setA contains 11 = " << setA.contains(11) << endl;		// check to see if contains() works.

	IntSet setB;

	cout << "***setB*****" << endl;
	cout << "setB is empty = " << setB.isEmpty() << endl;			// check to see if isEmpty() works.
	cout << "setB contains 1 = " << setB.contains(1) << endl;		// check to see if contains() works.

	setB.add(0);
	setB.add(1);
	setB.add(2);
	setB.add(3);
	setB.add(4);
	setB.add(5);
	setB.add(6);
	setB.add(7);
	setB.add(8);
	setB.add(88);
	setB.add(9);
	setB.add(10);
	setB.add(11);

	for (int i = 0; i < setB.size(); i++) {
		cout << "element [" << i << "] = " << setB.getIntSet(i) << endl;
	}

	cout << "setB is empty = " << setB.isEmpty() << endl;		// check to see if isEmpty() works.
	cout << "setB contains 11 = " << setB.contains(11) << endl;	// check to see if contains() works.

	cout << "END OF TEST 1" << endl;
	cout << endl;


	cout << "Start of TEST 2 - addall() function" << endl;

	setA.addAll(setB);

	for (int i = 0; i < setA.size(); i++) {// Should be 1-24 inclusive and 0 and 88.
		cout << "elements of setA after addAll: element [" << i << "] = " << setA.getIntSet(i) << endl; 
	}

	cout << endl;
	cout << "END OF TEST 2" << endl;

	cout << endl;
	cout << "Start of TEST 3 - removeDifferent() function" << endl;

	IntSet setC;

	setC.add(0);
	setC.add(1);// out
	setC.add(2);
	setC.add(3);// out
	setC.add(4);
	setC.add(5);// out
	setC.add(6);
	setC.add(7);// out
	setC.add(8);

	IntSet setD;

	setD.add(0);
	setD.add(2);
	setD.add(4);
	setD.add(6);
	setD.add(8);
	setD.add(22);
	setD.add(32);

	setC.removeDifferent(setD);

	for (int i = 0; i < setC.size(); i++) { // Set C should be { 0, 2, 4, 6, 8 } 
		cout << "elements of setC after removeDifferent: element [" << i << "] = " << setC.getIntSet(i) << endl;
	}

	cout << "END OF TEST 3" << endl;

	cout << endl;
	cout << "Start of TEST 4 - removeSame() function" << endl;

	IntSet setE;

	setE.add(0);// out
	setE.add(1);
	setE.add(2);// out
	setE.add(3);
	setE.add(4);// out
	setE.add(5);
	setE.add(6);// out
	setE.add(7);
	setE.add(8);// out

	IntSet setF;

	setF.add(0);
	setF.add(2);
	setF.add(4);
	setF.add(6);
	setF.add(8);
	setF.add(22);
	setF.add(32);

	setE.removeSame(setF);

	for (int i = 0; i < setE.size(); i++) { // Set E should be { 1, 3, 5, 7 } 
		cout << "elements of setE after removeSame: element [" << i << "] = " << setE.getIntSet(i) << endl;
	}

	cout << endl;

	for (int i = 0; i < setF.size(); i++) { // Set E should be {0, 2, 4, 6, 8, 22, 32 } 
		cout << "elements of setF after removeSame: element [" << i << "] = " << setF.getIntSet(i) << endl;
	}

	cout << "END OF TEST 4" << endl;


	cout << "START OF TEST 5 - EMPTY SETS" << endl;

	IntSet setG;

	IntSet setH;

	setG.addAll(setH);
	setA.addAll(setH);

	setG.removeDifferent(setH);
	setA.removeDifferent(setH);

	setG.removeSame(setH);
	setA.removeSame(setH);

	cout << "End of Test 5" << endl;

	cout << "*****END OF MAIN****" << endl;
}