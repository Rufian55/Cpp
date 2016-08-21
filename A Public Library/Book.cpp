/**********************************************************************************************************
** Author: Chris Kearns
** Date: 12/3/2015
** Description: Book.cpp is the Book class function implementation file and as such has the
** Book.hpp specification file included.
**********************************************************************************************************/
#include "Book.hpp"

Book::Book(std::string idc, std::string t, std::string a) {
	idCode = idc;
	title = t;
	author = a;
	checkedOutBy = NULL;	// intializes Book checkedOutBy to NULL (noone).
	requestedBy = NULL;		// initiailizes Book requestedBy to NULL (noone).
	location = ON_SHELF;	// initializes Book location to ON_SHELF.
}


/**********************************************************************************************************
**					function Book::getCheckOutLength()
**
** Description: Book getCheckedOutLength function definition that accesses and returns the CHECK_OUT_LENGTH
** variable.  Useful if additional Library object items are added later (i.e. CDs, DVD'd, etc.)
**********************************************************************************************************/
int Book::getCheckOutLength(){
	return CHECK_OUT_LENGTH;
}


/**********************************************************************************************************
**					function Book::getIdCode()
**
** Description: Book getIdCode function definition that accesses and returns the Book object's idCode
** variable.
**********************************************************************************************************/
std::string Book::getIdCode() {
	return idCode;
}


/**********************************************************************************************************
**					function Book::getTitle()
**
** Description: Book getTitle function definition that accesses and returns the Book object's title
** variable.
**********************************************************************************************************/
std::string Book::getTitle() {
	return title;
}


/**********************************************************************************************************
**					function Book::getAuthor()
**
** Description: Book getauthor function definition that accesses and returns the Book objcect's author
** variable.
**********************************************************************************************************/
std::string Book::getAuthor() {
	return author;
}


/**********************************************************************************************************
**					function Book::getLocation()
**
** Description: Book getLocation function definition that accesses and returns the Book objcect's location
** variable.
**********************************************************************************************************/
Locale Book::getLocation() {
	return location;
}


/**********************************************************************************************************
**					function Book::setLocation()
**
** Description: Book setLocation function definition that sets the Book objcect's location variable.
**********************************************************************************************************/
void Book::setLocation(Locale theLocale) {
	location = theLocale;
}


/**********************************************************************************************************
**					function Book::getCheckedOutBy()
**
** Description: Book getCheckedOutBy function definition that returns a pointer to the Book object's
** checkedOutBy variable (namely, the memory address of the Patron's ID).
**********************************************************************************************************/
Patron * Book::getCheckedOutBy() {
	return checkedOutBy;
}


/**********************************************************************************************************
**					function Book::setCheckedOutBy()
**
** Description: Book setCheckedOutBy function definition that sets the Book object's checkedOutBy variable.
** Paramter is a pointer (the memory address) of the Patron's ID.
**********************************************************************************************************/
void Book::setCheckedOutBy(Patron *aPatronID) {
	checkedOutBy = aPatronID;
}


/**********************************************************************************************************
**					function Book::getRequestedBy()
**
** Description: Book getRequestedBy function definition that returns a pointer to the Book object's
** requestedBy variable (namely, the memory address of the Patron's ID).
**********************************************************************************************************/
Patron * Book::getRequestedBy() {
	return requestedBy;
}


/**********************************************************************************************************
**					function Book::setRequestedBy()
**
** Description: Book setRequestedBy function definition that sets the Book objcect's requestedBy variable.
** Parameter is a pointer (the memory address) of the Patron's ID.
**********************************************************************************************************/
void Book::setRequestedBy(Patron *aPatronID) {
	requestedBy = aPatronID;
}


/**********************************************************************************************************
**					function Book::getDateCheckedOut()
**
** Description: Book getDateCheckedOut function definition that returns the Book object's dateCheckedOut
** variable.
**********************************************************************************************************/
int Book::getDateCheckedOut() {
	return dateCheckedOut;
}


/**********************************************************************************************************
**					function Book::setDateCheckedOut()
**
** Description: Book setDateCheckedOut function definition that sets the Book object's dateCheckedOut
** variable.
**********************************************************************************************************/
void Book::setDateCheckedOut(int date) {
	dateCheckedOut = date;
}