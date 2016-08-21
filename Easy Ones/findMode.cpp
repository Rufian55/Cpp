/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/11/2015
** Description: findMode.cpp is a function file that returns a vector containing the mode(s)
** of an array (The number that appears most often).  The vector will reuturn the mode or modes in
** ascending order. findMode()'s input parameters are the array and the size of the array.  See function
** description for more information. 
**********************************************************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

// Vector function prototype.
vector<int> findMode(int anArray[], int size); 

/**********************************************************************************************************
				function findMode()
** Description: findMode() is a function that returns a vector containing the mode(s)
** of an input array. The returned vector will behave as follows:
** 1. If there is just a single most frequent value, the vector will only contain that one value.
** 2. If multiple values tie for maximum frequency, the vector will contain all such values.
** 3. If the input array contains only elements that appear once, then the vector will contain all elements.
** 4. The returned vector will only contain multiple occurring array elements once.
** 5. The returned values in the vector will be in ascending order.
** findMode()'s input parameters are the array memory address and the size of the array.
** Usage example:  findMode(someArray, 10); where "10" is the array size.
**********************************************************************************************************/
vector<int> findMode(int anArray[], int size) {
	vector<int> result;
	int highFreq = 0;	// Highest frequency of occurence of anArray elements, including ties.

	// First iteration through anArray determining the highest frequency of occurrence of anArray's values.
	for (int i = 0; i<size; i++) {
		int count = 1; 
		for (int j=i+1; j < size; j++) {
			if (anArray[i] == anArray[j])
				count++;
		}
		if (count > highFreq)
			highFreq = count;
	}

	/* Second iteration through anArray determining which elements of anArray occur the same
	   amount as our "predetermined" highFreq value.*/
	for (int i=0; i<size; i++) {
		int count = 1;
		for (int j=i+1; j < size; j++) {
			if (anArray[i] == anArray[j])
				count++;
		}
		/* If our nested for iteration yields a count variable that is equivalent to our previously
		   determined highFreq variable, append it to our result vector. If more than one element
		   == our highFreq, then each "qualifying" element gets appended. If all elements of anArray
		   are different, highFreq = 1, and all elements get appended to result vector. */
		if (count == highFreq)
			result.push_back(anArray[i]);
	}
	
	// Sort the populated vector in ascending order.
	std::sort(result.begin(), result.end());
	
	// Finally, we return our result vector.
	return result;
}


int main() {

	int val1, val2, val3, val4, val5, val6, val7, val8, val9, val10;
	
	cout << "Please enter your arrays first value and press <Enter>: " << endl;
	cin >> val1;
	cout << "Please enter your arrays second value and press <Enter>: " << endl;
	cin >> val2;
	cout << "Please enter your arrays third value and press <Enter>: " << endl;
	cin >> val3;
	cout << "Please enter your arrays fourth value and press <Enter>: " << endl;
	cin >> val4;
	cout << "Please enter your arrays fifth value and press <Enter>: " << endl;
	cin >> val5;
	cout << "Please enter your arrays sixth value and press <Enter>: " << endl;
	cin >> val6;
	cout << "Please enter your arrays seventh value and press <Enter>: " << endl;
	cin >> val7;
	cout << "Please enter your arrays eighth value and press <Enter>: " << endl;
	cin >> val8;
	cout << "Please enter your arrays ninth value and press <Enter>: " << endl;
	cin >> val9;
	cout << "Please enter your arrays tenth value and press <Enter>: " << endl;
	cin >> val10;

	const int ARRAY_SIZE = 10;
	int someArray[ARRAY_SIZE] = { val1, val2, val3, val4, val5, val6, val7, val8, val9, val10 };

	vector<int> result = findMode(someArray, ARRAY_SIZE);

	cout << endl << "The mode(s) of your array are: ";

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}
