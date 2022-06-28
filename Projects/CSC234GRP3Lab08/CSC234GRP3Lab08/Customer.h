/**
 * \author Daniel Miranda
 * \date 4/30/2022
 * \description Customer class to implement customer data and functions
 */

#pragma once
#include "OrderList.h"

class Customer
{
	friend ostream& operator<<(ostream&, const Customer&);
public:
	Customer();
	Customer(string, string, string, OrderList);
	OrderList getOrders();
	void AddOrder(Order);
	void UpdateOrders(string, int);
	void CancelOrder(string);
	string getCustomerName();
	string getAddress();
	string getEmail();
	double checkoutOrders();
	bool operator==(const Customer&) const;
	bool operator!=(const Customer&) const;
private:
	string name;
	string address;
	string email;
	OrderList orders;
};
