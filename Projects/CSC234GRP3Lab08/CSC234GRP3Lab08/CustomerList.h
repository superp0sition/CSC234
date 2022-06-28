/**
 * \author David Badcoe
 * \date 4/30/2022
 * \description LinkedList containing customers with additional functions
 */

#pragma once
#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include "linkedList.h"
#include "Customer.h"
#include "fstream"

class CustomerList : public linkedListType<Customer>
{
	friend ostream& operator<<(ostream&, const CustomerList&);
public:
	void AddCustomer(Customer&);
	bool SearchCustomerByName(string) const;
	Customer getCustomerByName(string) const;
	void UpdateCustomer(Customer&);
	void UpdateDataFile(ofstream&);
};

#endif
