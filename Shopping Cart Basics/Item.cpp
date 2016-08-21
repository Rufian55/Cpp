/**********************************************************************************************************
** Author: Chris Kearns
** Date: 11/18/2015
** Description: Item.cpp is the Item class function implementation file and as such has the
** Item.hpp specification file included.
**********************************************************************************************************/
#include "Item.hpp"

Item::Item(std::string newName, double newPrice, int newQuantity) {
	setName(newName);
	setPrice(newPrice);
	setQuantity(newQuantity);
}

// Default Item constructor that takes no arguments and simply sets default values.
Item::Item() {
	setName("");
	setPrice(0.0);
	setQuantity(0);
}

// Our setName() method that takes one argument - the Item's "name" value.
void Item::setName(std::string newName) {
	name = newName;
}

// Our setPrice() method that takes one argument - the Item's "price" value
void Item::setPrice(double newPrice) {
	price = newPrice;
}

// Our setQuantity() method that takes one argument - the Item's "quantity" value.
void Item::setQuantity(int newQuantity) {
	quantity = newQuantity;
}

// Our getName() method that returns an  Item's "name" value.
std::string Item::getName() {
	std::string itemName = name;
	return itemName;
}

// Our getPrice() method that returns an Item's "price" value.
double Item::getPrice() {
	double itemPrice = price;
	return itemPrice;
}

// Our getQuantity() method that returns an Item's "quantity" value.
int Item::getQuantity() {
	int itemQuantity = quantity;
	return itemQuantity;
}


/* //Testing script for Item class.
#include "Item.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {

	Item dog("Beagle", 9.95, 7);

	std::string dogsname = dog.getName();
	cout << dogsname << endl;
	double dogsprice = dog.getPrice();
	cout << dogsprice << endl;
	int dogsquantity = dog.getQuantity();
	cout << dogsquantity << endl;

	Item cat;
	std::string catsname = cat.getName();
	cout << catsname << endl;
	double catsprice = cat.getPrice();
	cout << catsprice << endl;
	int catsquantity = cat.getQuantity();
	cout << catsquantity << endl;

}
*/