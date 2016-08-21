/**********************************************************************************************************
** Author: Chris Kearns
** Date: 10/28/2015
** Description: BankAccount.cpp is the BankAccount class function implementation file and as
** such has the BankAccount.hpp specification file included.
**********************************************************************************************************/
#include "BankAccount.hpp"
#include <iomanip>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Default constructor for "no parmameters provided" initializing our private member variables.
BankAccount::BankAccount() {
	customerName = "Default No Name";
	customerID = "Default No ID";
	double balance = 0.00;
	customerBalance = balance;
}

// Construtor with "three parameters provided" initializing our private member variables.
BankAccount::BankAccount(std::string name, std::string ID, double balance) {
	customerName = name;
	customerID = ID;
	customerBalance = balance;
}

/* getCustomerName() function that, when called after BankAccount object has been instantiated,
   returns the customer's name. */ 
std::string BankAccount::getCustomerName() {
	std::string name;
	name = customerName;
	return name;
}

/* Our getCustomerID() function that, when called after BankAccount object has been instantiated,
   returns the customer's ID string. */  
std::string BankAccount::getCustomerID() {
	std::string ID;
	ID = customerID;
	return ID;
}

/* Our getCustomerBalance() function that, when called after BankAccount object has been
  instantiated, returns the customer's balance.  Also useful for returning customer's balance
  after the withdraw or deposit functions are called. (See below) */
double BankAccount::getCustomerBalance() {
	double balance = customerBalance;
	return balance;
}

/* Withdraw function that deducts the paratmeter wdAmount as inputted and updates customerBalance.
   Account balance is allowed to go negative.*/
void BankAccount::withdraw(double wdAmount) {
	double balance = customerBalance;
	balance -= wdAmount;
	customerBalance = balance;
}

/* Deposit function that adds the paramter depAmount as inputted and updates customerBalance.
   Account balance is allowed to remain negative if an insufficient amount is deposited. */
void BankAccount::deposit(double depAmount) {
	double balance = customerBalance;
	balance += depAmount;
	customerBalance = balance;
}


int main() {
	// Instantiating our BankAccount object with three parameters.
	BankAccount yourAccount("CG Kearns", "A5B4C3D5E4F3G5", 500.01);

	// Testing routine to ensure paramters are being accepted and stored.
	cout << endl;
	cout << "Customer Name = " << yourAccount.getCustomerName() << endl;
	cout << endl;
	cout << "Customer ID = " << yourAccount.getCustomerID() << endl;
	cout << endl;
	cout << "Customer Balance = " << yourAccount.getCustomerBalance() << endl;
	cout << endl;

	// Testing our withdraw method.
	yourAccount.withdraw(51.07);

	cout << "Balance after withdrawal = " << yourAccount.getCustomerBalance() << endl;
	cout << endl;
	
	// Tesing our deposit method.
	yourAccount.deposit(102.04);

	cout << "Balance after deposit = " << yourAccount.getCustomerBalance() << endl;
	cout << endl;

	// Instantiating our type BankAccount object with no parameters, so defaults are utilized.
	BankAccount myAccount;

	// Testing routine to ensure default paramters are being accepted and stored.
	cout << endl;
	cout << "Customer Name = " << myAccount.getCustomerName() << endl;
	cout << endl;
	cout << "Customer ID = " << myAccount.getCustomerID() << endl;
	cout << endl;
	cout << "Customer Balance = " << myAccount.getCustomerBalance() << endl;
	cout << endl;

	// Testing our withdraw method.
	myAccount.withdraw(0.69);

	cout << "Balance after withdrawal = " << myAccount.getCustomerBalance() << endl;
	cout << endl;

	// Tesing our deposit method.
	myAccount.deposit(120.02);

	cout << "Balance after deposit = " << myAccount.getCustomerBalance() << endl;
	cout << endl;
}