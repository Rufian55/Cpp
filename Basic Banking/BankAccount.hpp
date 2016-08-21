/**********************************************************************************************************
** Author: Chris Kearns
** Date: 10/28/2015
** Description: BankAccount.hpp header file is the class specification file for 
** BankAccount.cpp and as such must be included.
**********************************************************************************************************/
#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP 
#include <string>

class BankAccount {
	private:
		std::string customerName;
		std::string customerID;
		double customerBalance;
	public:
		BankAccount(std::string customerName, std::string customerID, double customerBalance);
		BankAccount();
		
		// Getter function prototypes.
		std::string getCustomerName();
		std::string getCustomerID();
		double getCustomerBalance();
		
		// Account withdraw and deposit function prototypes.
		void withdraw(double);
		void deposit(double);
};
#endif