/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/25/2015
** Description: IntSet.hpp header file is the class specification file for IntSet.cpp and as such
** must be included.
**********************************************************************************************************/
#ifndef INTSET_HPP 
#define INTSET_HPP

class IntSet {
	private:
		int *intSet;	// Pointer to our array of ints.
		int sizeArray;	// The size of the array - updated by add() method.
		int numVals;	// Sentinal - the number of values stored in the intSet array.
	public:
		IntSet();
		~IntSet();
		int size() const;
		bool isEmpty();
		bool contains(int) const;
		void add(int);	
		void remove(int);
		void addAll(const IntSet&);
		void removeDifferent(const IntSet&);
		void removeSame(const IntSet&);
		int getIntSet(int);
};
#endif