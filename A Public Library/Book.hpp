/**********************************************************************************************************
** Author: Chris Kearns
** Date: 12/3/2015
** Description: Book.hpp is the Book class function declaration file.
**********************************************************************************************************/
#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>

// Forward declaration - Book & Patron need to know about each other (avoids cyclic dependency).
class Patron;

/* These three locations are mutually exclusive, but note that
   a Book can be on request for a Patron while being checked
   out to another Patron.  In that case the Book's location is
   CHECKED_OUT, and when it is returned, it's location will
   become ON_HOLD_SHELF. */
enum Locale { ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT };

class Book {
private:
	std::string idCode;		// a unique identifier for a Book (think library bar code, not ISBN).
	std::string title;		// cannot be assumed to be unique.
	std::string author;		// also assuemed to not be unique.
	Locale location;		// see enumeration at line 13.
	Patron* checkedOutBy;	// pointer to the Patron who has it checked out (if any).
	Patron* requestedBy;	// pointer to Patron who requested it (if any); Book can only be requested by 1 Patron at a time.
	int dateCheckedOut;		// when a book is checked out, this will be set to the currentDate of the Library.

public:
	static const int CHECK_OUT_LENGTH = 21;				// 21 days, no more, no less.
	Book(std::string idc, std::string t, std::string a);	// Prototype Book constructor
	int getCheckOutLength();							// returns 21
	std::string getIdCode();
	std::string getTitle();
	std::string getAuthor();
	Locale getLocation();
	void setLocation(Locale);
	Patron* getCheckedOutBy();
	void setCheckedOutBy(Patron*);
	Patron* getRequestedBy();
	void setRequestedBy(Patron*);
	int getDateCheckedOut();
	void setDateCheckedOut(int);
};
#endif