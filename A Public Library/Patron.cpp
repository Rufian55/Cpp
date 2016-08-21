/**********************************************************************************************************
** Author: Chris Kearns
** Date: 12/3/2015
** Description: Patron.cpp is the Patron class function implementation file and as such has the
** Patron.hpp specification file included.
**********************************************************************************************************/
#include "Patron.hpp"
#include <string>

Patron::Patron(std::string idn, std::string n) {
	idNum = idn;
	name = n;
	fineAmount = 0;
}


/**********************************************************************************************************
**					function Patron::getIdNum()
**
** Description: Patron getIdNum function definition that accesses and returns the Patron object's idNum
** variable.
**********************************************************************************************************/
std::string Patron::getIdNum() {
	return idNum;
}


/**********************************************************************************************************
**					function Patron::getName()
**
** Description: Patron getName function definition that accesses and returns the Patron object's name
** variable.
**********************************************************************************************************/
std::string Patron::getName(){
	return name;
}


/**********************************************************************************************************
**					function Patron::getCheckOutBooks()
**
** Description: Patron getCheckedOutBooks function definition that returns the vector of pointers to Book
** objects that an individual Patron has checked out. The vector's name is checkedOutBooks. The vector
** contains pointers to Book object's IdCode variable.
**********************************************************************************************************/
std::vector<Book*> Patron::getCheckedOutBooks() {
	return checkedOutBooks;
}


/**********************************************************************************************************
**					function Patron::addBook()
**
** Description: Patron addBook function definition that adds a pointer to a Book object's idCode variable 
** in the individual Patron's checked out vector. The vector's name is checkedOutBooks. The vector contains
** pointers to Book object's IdCode variable.
**********************************************************************************************************/
void Patron::addBook(Book * bId) {
	checkedOutBooks.push_back(bId);
}


/**********************************************************************************************************
**					function Patron::removeBook()
**
** Description: Patron removeBook function definition that removes a pointer to a Book object's idCode
** variable from an individual Patron's checked out vector.  The vector's name is checkedOutBooks.  The 
** vector contains pointers to Book object's IdCode variable.
**********************************************************************************************************/
void Patron::removeBook(Book * bId) {
	int flag = -1;
	for (int i = 0; i < checkedOutBooks.size(); i++) {
		if (checkedOutBooks[i] == bId)
			flag = i;
		if(flag != -1)
		checkedOutBooks.erase(checkedOutBooks.begin() + flag);
	}
}


/**********************************************************************************************************
**					function Patron::getFineAmount()
**
** Description: Patron getFineAmount function definition that accesses and returns the Patron object's
** private fineAmount variable.
**********************************************************************************************************/
double Patron::getFineAmount() {
	return fineAmount;
}


/**********************************************************************************************************
**					function Patron::amendFine()
**
** Description: Patron amendFine function definition that accesses and adjusts the Patron object's 
** private fineAmount variable. This amount is allowed to go negative (credit balance allowed).
**********************************************************************************************************/
void Patron::amendFine(double amount) {
	fineAmount -= amount;
}