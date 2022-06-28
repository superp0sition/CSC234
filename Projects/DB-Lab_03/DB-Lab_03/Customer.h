#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
// in my header here, I had added two includes for CheckingAccount and SavingsAccount
// this gave me headaches for a few hours since I didn't realize these classes were being included before their base
using std::string;


class Customer {
public:
	/**
	 * \brief Constructor for each of the data members of Customer
	 * \param _first first name of the customer
	 * \param _last last name of the customer
	 * \param _address address of the customer
	 * \param _email email address of the customer
	 */
	Customer(string _first, string _last, string _address, string _email);
	/**
	 * \brief Copy constructor for Customer (unused)
	 * \param _c Customer to be copied
	 */
	explicit Customer(Customer const* _c);
	void display();

	friend std::ostream& operator<<(std::ostream& out, const Customer& c);
private:
	string _first;
	string _last;
	string _address;
	string _email;
};

#endif // !CUSTOMER_H