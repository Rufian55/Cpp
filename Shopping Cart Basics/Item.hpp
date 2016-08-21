/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/18/2015
** Description: Item.hpp header file is the class specification file for Item.cpp and as such
** must be included.
**********************************************************************************************************/
#ifndef ITEM_HPP 
#define ITEM_HPP 
#include <string>

class Item {
	private:
		std::string name;
		double price;
		int quantity;
	public:
		Item(std::string, double, int);
		Item();

	// Our setter function prototypes.
	void setName(std::string);
	void setPrice(double);
	void setQuantity(int);

	// Our getter function prototypes.
	std::string getName();
	double getPrice();
	int getQuantity();

};
#endif