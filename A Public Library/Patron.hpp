/**********************************************************************************************************
** Author: Chris Kearns
** Date: 12/3/2015
** Description: Patron.hpp is the Patron class declartion file.
**********************************************************************************************************/
#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>
#include "Book.hpp"

//class Library; is not needed!

class Patron {
private:
	std::string idNum;					// Unique identifier for a Patron.
	std::string name;					// Cannot assume to be unique.
	std::vector<Book*> checkedOutBooks;	// Vector of pointers to Books that Patron currently has checkedOut.
	double fineAmount;					// How much the Patron owes the Library in late fines.

public:
	Patron(std::string idn, std::string n);
	std::string getIdNum(); 
	std::string getName();
	std::vector<Book*> getCheckedOutBooks();
	void addBook(Book* b);
	void removeBook(Book* b);
	double getFineAmount();
	void amendFine(double amount);
};
#endif