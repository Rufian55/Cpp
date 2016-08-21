/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/18/2015
** Description: ShoppingCart.hpp header file is the class implementation file for
** ShoppingCart class and as such must have ShoppingCart.hpp included.  See main() for use example.
**********************************************************************************************************/
#include "ShoppingCart.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Our addItem() function that takes a reference to an Item object and declares it a pointer.
void ShoppingCart::addItem(Item *val) {
	itemArray[arrayEnd] = val;		// Add pointer to the Item to our storage array at position "arrayEnd".
	arrayEnd++;
}

double ShoppingCart::totalPrice() {
	double total = 0;
	for (int i = 0; i < arrayEnd; i++) {
		double aPrice = (*itemArray[i]).getPrice();  
		int aQuantity = (*itemArray[i]).getQuantity();
		total += (aPrice * aQuantity);
	}
	return total;
}

ShoppingCart::ShoppingCart() {
	for (int i = 0; i < 100; i++) {
		itemArray[i] = NULL;
		}
	arrayEnd = 0;
}

int main() {

	Item a("affidavit", 179.99, 12);

	Item b("Bildungsroman", 0.7, 20);

	Item c("capybara", 4.5, 6);

	Item d("dirigible", 0.05, 16);

	ShoppingCart sc1;

	sc1.addItem(&a);

	sc1.addItem(&b);

	sc1.addItem(&c);

	sc1.addItem(&d);

	double diff = sc1.totalPrice();

	cout << diff << endl;
}