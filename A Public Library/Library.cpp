/**********************************************************************************************************
** Author: Chris Kearns
** Date: 12/3/2015
** Description: Library.cpp is the Library class function implementation file and as such has the
** Library.hpp specification file included. Program is geared towards a public library, but could be any
** system of checkout with monetary accountabilty for return.
**********************************************************************************************************/
#include "Library.hpp"
#include <iostream>
using std::cout;
using std::endl;


Library::Library(){
	currentDate = 0;
}


/**********************************************************************************************************
**					function Library::addBook()
**
** Description: Library addBook function definition that adds a Book object to the Library holdings vector.
** Parameter is a pointer to a Book object.
**********************************************************************************************************/
void Library::addBook(Book *aBook) {
	holdings.push_back(aBook);
}


/**********************************************************************************************************
**					function Library::addPAtron()
**
** Description: Library addPatron function definition that accepts a Patron object and adds it to the 
** Library's members vector.
**********************************************************************************************************/
void Library::addPatron(Patron *aPatronID){
	members.push_back(aPatronID);
}


/**********************************************************************************************************
**					function Library::checkOutBook()
**
** Description: Library checkOutBook function definition that is designed as follows:
** If the specified Book is not in the Library, return "book not found".
** if the specified Patron is not in the Library, return "patron not found".
** if the specified Book is already checked out, return "book already checked out".
** if the specified Book is on hold by another Patron, return "book on hold by other patron".
** otherwise update the Book's checkedOutBy, dateCheckedOut and Location;
** also, if the Book was on hold for this Patron, update requestedBy; update the Patron's checkedOutBooks; 
** and assuming everything executed, return "check out successful"
**********************************************************************************************************/
std::string Library::checkOutBook(std::string pID, std::string bID) {
	if (getBook(bID) != NULL) {
		if (getPatron(pID) != NULL) {
			if (getBook(bID)->getLocation() == CHECKED_OUT) {
				return "book already checked out";
			}
			else {	
				if (((getBook(bID)->getLocation() == ON_HOLD_SHELF)
					&& (getBook(bID)->getRequestedBy() == getPatron(pID)))
					|| (getBook(bID)->getLocation() == ON_SHELF)) {

						getBook(bID)->setCheckedOutBy(getPatron(pID));
						getBook(bID)->setDateCheckedOut(currentDate);
						getBook(bID)->setLocation(CHECKED_OUT);
						getBook(bID)->setRequestedBy(NULL);
						getPatron(pID)->addBook(getBook(bID));
						
						return "Check out successful";
					}
					else {
						return "Book on hold by anoother patron";
				}
			}
		}
		else { return "Patron not found"; }
	}
	else { return "Book not found"; } 
}


/**********************************************************************************************************
**					function Library::returnBook()
**
** Description: Library returnBook function definition that:
** if the specified Book is not in the Library, returns "book not found".
** if the Book is not checked out, return "book already in library".
** updates the Patron's checkedOutBooks.
** updates the Book's location depending on whether another Patron has requested it
** updates the Book's checkedOutBy
** and finally returns "return successful"
** Note that we do not call the Books setCheckedOutDate(NULL) method as we want to calculate any fines due.
**********************************************************************************************************/
std::string Library::returnBook(std::string bID){
	if (getBook(bID) != NULL) {
		if (getBook(bID)->getLocation() == CHECKED_OUT) {
			std::string pID = getBook(bID)->getCheckedOutBy()->getIdNum();
			getPatron(pID)->removeBook(getBook(bID));
			if(getBook(bID)->getRequestedBy() != NULL) {
				getBook(bID)->setLocation(ON_HOLD_SHELF);
			}
			else {
				getBook(bID)->setLocation(ON_SHELF);
			}
			getBook(bID)->setCheckedOutBy(NULL);

			return "Return successful";
		}
		else { return "Book already in library"; }
	}
	else { return "Book not found"; }
}


/**********************************************************************************************************
**					function Library::requestBook()
**
** Description: Library requestBook function definition that:
** if the specified Book is not in the Library, returns "Book not found"
** if the specified Patron is not in the Library, returns "Patron not found"
** if the specified Book is already requested, return "Book already on hold"
** updates the Book's requestedBy var
** if the Book is on the shelf, update its location to ON_HOLD_SHELF
** and finally, return "request successful"
**********************************************************************************************************/
std::string Library::requestBook(std::string pID, std::string bID){
	if (getBook(bID) != NULL) {
		if (getPatron(pID) != NULL) {
			if (getBook(bID)->getRequestedBy() == NULL) {
				getBook(bID)->setRequestedBy(getPatron(pID));
				if (getBook(bID)->getLocation() == ON_SHELF) {
					getBook(bID)->setLocation(ON_HOLD_SHELF);
				}
				return "Request successful";
			}
			else { return "Book already on hold"; }
		}
		else { return "Patron not found"; }
	}
	else { return "Book not found"; }
}


/**********************************************************************************************************
**					function Library::payFine()
**
** Description: Library payFine function definition that checks if Patron specified by pID argument exists
** in the Library memebers vector utilizing the getPatron function, and if so, modifies the Patron's 
** fineAmount variable via the amendFine function. Returns "payemnt successful" if Patron is found, "patron
** not found" otherwise.
**********************************************************************************************************/
std::string Library::payFine(std::string pID, double payment){
	if (getPatron(pID) != NULL) {
		getPatron(pID)->amendFine(payment);
		return "Payment successful";
	}
	else 
		return "Patron not found";
}


/**********************************************************************************************************
**					function Library::incrementCurrentDate()
**
** Description: Library incrementCurrentDate function definition that increments the currentDate
** variable for the Library simulator, increases each Patron's fines by 10 cents for each overdue Book
** they have checked out (using amendFine) as follows:
** If a book is checked out on day 0, then on day 1, the patron has had it for 1 day.  On day 21, the
** patron has had it for 21 days, so it is still not overdue. On day 22, the book is overdue and fines
** will begin accrueing.
**********************************************************************************************************/
void Library::incrementCurrentDate() {
	currentDate++;
	for (int i = 0; i < members.size(); i++) {
		std::string pId = members[i]->getIdNum();
		std::vector<Book*> temp = getPatron(pId)->getCheckedOutBooks();
		for (int i = 0; i < temp.size(); i++) {
			if (currentDate - temp[i]->getDateCheckedOut() > temp[i]->getCheckOutLength()) {
				getPatron(pId)->amendFine(-0.10);
			}
		}
	}
}


/**********************************************************************************************************
**					function Library::getPatron()
**
** Description: Library getPatron function definition that searchs the Library "members" vector of pointers
** to Patron objects, accesses each Patron object's IdNum field with getIdNum() and if equivalent to the
** getPatron function argument pID, returns the corresponding members vector pointer to that Patron object.
**********************************************************************************************************/
Patron * Library::getPatron(std::string pID) {
	Patron* ptr = NULL;
	for (int i = 0; i < members.size(); i++) {
		if (members[i]->getIdNum() == pID) {
			ptr = members[i];
		}
	}
	return ptr;
}


/**********************************************************************************************************
**					function Library::getBook()
**
** Description: Library getBook function definition that searchs the Library "holdings" vector of pointers
** to Book objects, accesses each Book object's IdCode field with getIdCode() and if equivalent to the
** getBook function argument bID, returns the corresponding holdings vector pointer to that Book object.
**********************************************************************************************************/
Book * Library::getBook(std::string bID){
	Book* ptr = NULL;	
	for (int i = 0; i < holdings.size(); i++) {
		if ( holdings[i]->getIdCode() == bID) {
			ptr = holdings[i];
		}
	}
	return ptr;
}


int main() {
	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");
	Patron p3("cgk", "Coder");
	Library lib;
	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.addPatron(&p3);

	cout << "1. Book b2 location is " << b2.getLocation() << endl;

	cout << "2. Book b2 checkOutBook call returns " << lib.checkOutBook("bcd", "234") << endl;

	cout << "3. Book b2 location is " << b2.getLocation() << endl;

	cout << "4. Book b2 request for ON_HOLD_SHELF returns " << lib.requestBook("abc", "234") << endl;

	cout << "5. book b2 location after after ON_HOLD_SHELF request call returns " << b2.getLocation() << endl;

	cout << "6. Book b2 request for ON_HOLD_SHELF returns " << lib.requestBook("cgk", "234") << endl;

	cout << "7. book b2 location after 2nd b2 requestBook call returns " << b2.getLocation() << endl;

	for (int i = 0; i < 27; i++)
		lib.incrementCurrentDate();

	cout << "8. Book b2 returnBook call returns " << lib.returnBook("234") << endl;

	cout << "9. book b2 location after returnBook call returns " << b2.getLocation() << endl;

	cout << "10. Book b2 checkout_2 call returns " << lib.checkOutBook("bcd", "234") << endl;

	cout << "11. Book b2 checkout_2 call returns " << lib.checkOutBook("abc", "234") << endl;

	lib.checkOutBook("abc", "345");

	for (int i = 0; i < 24; i++)
		lib.incrementCurrentDate();

	lib.payFine("bcd", 0.40);
	lib.payFine("abc", 0.00);
	double p1Fine = p1.getFineAmount();
	double p2Fine = p2.getFineAmount();
	cout << "Patron p1 fine is " << p1Fine << endl;
	cout << "Patron p2 fine is " << p2Fine << endl;
	
	return 0;
}
