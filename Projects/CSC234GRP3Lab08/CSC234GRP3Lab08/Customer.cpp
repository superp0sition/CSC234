/**
 * \author Daniel Miranda
 * \date 4/30/2022
 * \description Customer class to implement customer data and functions
 */

#include "Customer.h"

#include <iomanip>

Customer::Customer() : name(""), address(""), email("")
{
}

Customer::Customer(string name, string address, string email, OrderList orders) : name(name), address(address), email(email), orders(orders)
{
}

OrderList Customer::getOrders()
{
	return orders;
}

void Customer::AddOrder(Order order)
{
	orders.AddOrder(order);
}

void Customer::UpdateOrders(string order, int number)
{
	orders.UpdateOrder(order, number);
}

void Customer::CancelOrder(string s)
{
	orders.CancelOrder(s);
}

string Customer::getCustomerName()
{
	return name;
}


string Customer::getAddress()
{
	return address;
}

string Customer::getEmail()
{
	return email;
}

double Customer::checkoutOrders()
{
	return orders.CalculateSubtotal();
}

bool Customer::operator==(const Customer&) const
{
	return (name == Customer().name && address == Customer().address
		&& email == Customer().email);
}

bool Customer::operator!=(const Customer&) const
{
	return(name != Customer().name && address != Customer().address
		&& email != Customer().email);
}

ostream& operator<<(ostream& out, const Customer& c)
{
	out << string(43, '*') << '\n';
	out <<
		setw(10) << left << "Name: " << c.name << '\n' <<
		setw(10) << left << "Address: " << c.address << '\n' <<
		setw(10) << left << "Email: " << c.email << '\n';

	out << '\n' << string(16, '-') << "Book Orders" << string(16, '-') << '\n';
	out << c.orders;
	out << string(43, '*') << '\n';
	return out;
}
