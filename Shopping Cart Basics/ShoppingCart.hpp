/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/18/2015
** Description: ShoppingCart.hpp header file is the class specification file for 
** ShoppingCart.cpp and as such must be included.
**********************************************************************************************************/
#ifndef SHOPPING_CART_HPP 
#define SHOPPING_CART_HPP
#include "Item.hpp"

class ShoppingCart{
	private:
		Item *itemArray[100];	// Our array of upto MAX_VALUE pointers to objects of class Item. 
		int arrayEnd;			/* Our indexing variable to control the pointer array's "next avaialble"
							   element for storing an Item. */ 
	public:
		void addItem(Item *);
		double totalPrice();
		ShoppingCart();
};
#endif