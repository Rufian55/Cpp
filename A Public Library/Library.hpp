/**********************************************************************************************************
** Author: Chris Kearns
** Date: 12/3/2015
** Description: Library.hpp is the Library class function declaration file.
**********************************************************************************************************/
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>
#include "Patron.hpp"

class Library {
private:
	std::vector<Book*> holdings;	// a vector of pointers to Books in the Library
	std::vector<Patron*> members;	// a vector of pointers to Patrons in the Library
	int currentDate;			/* Stores the current date represented as an integer number
							   of "days" since the Library object was created. */
public:
	Library();
	void addBook(Book*);
	void addPatron(Patron*);
	std::string checkOutBook(std::string pID, std::string bID);
	std::string returnBook(std::string bID);
	std::string requestBook(std::string pID, std::string bID);
	std::string payFine(std::string pID, double payment);
	void incrementCurrentDate();
	Patron* getPatron(std::string pID);
	Book* getBook(std::string bID);
};
#endif