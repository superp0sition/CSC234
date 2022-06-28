#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>
#include "Customer.h"

class Account {
public:
	virtual ~Account() = default;
	/**
	 * \brief Default constructor for Account
	 */
	Account();
	/**
	 * \brief Constructor for all data members of Account
	 * \param balance Balance in the account
	 * \param _c Customer pointer 
	 * \param id Identifier for the account
	 */
	Account(double balance, Customer* _c, string id);
	/**
	 * \brief Returns the balance of the account
	 * \return returns balance
	 */
	double get_balance();
	/**
	 * \brief Sets the balance of the account
	 * \param bal Balance to set account to 
	 */
	void set_balance(double bal);
	/**
	 * \brief Displays account information to cout
	 */
	virtual void display();
	/**
	 * \brief Attempts to deposit money into account, returns if the operation was successful
	 * \param amount amount to be deposited
	 * \return returns if successful
	 */
	virtual bool deposit(double amount);
	/**
	 * \brief Attempts to withdraw amount from account 
	 * \param amount the amount to withdraw
	 * \return returns if successful
	 */
	virtual bool withdraw(double amount);
	/**
	 * \brief dereferences and returns the customer
	 * \return returns the customer dereferenced
	 */
	Customer getCus();
private:
	double balance;
	Customer* _c;
	string id;
};

#endif // !ACCOUNT_H
