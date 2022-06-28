#include<iostream>
#include<iomanip>
#include"Customer.h"
#include"OrderList.h"
#include"CustomerList.h"
using namespace std;

Customer::Customer()
{
	name = "";
	address = "";
	email = "";
	orders = OrderList();
}

Customer::Customer(string _name, string _address, string _email, OrderList _orders)
{
	name = _name;
	address = _address;
	email = _email;
	orders = _orders;
}

ostream& operator<<(ostream& osObject, const Customer& customerObj)
{
	osObject << "************************************************************" << '\n'
		<< setw(10) << left << "Name: " <<  setw(30) << customerObj.name << '\n'
		<< setw(10) << left << "Address: " << setw(30) << customerObj.address << '\n'
		<< setw(10) << left << "Email: " << setw(30) << customerObj.email << '\n' << '\n'
		<< setw(10) << left << "---------- Book Orders ---------- : " << '\n'
		<< customerObj.orders 
		<< "************************************************************" << endl;
	return osObject;
}

//bool Customer::checkCustomerName(string _name)
//{
//	return(name == _name);
//}

//void Customer::setOrderList(OrderList myOrders)
//{
//	orders = myOrders;
//}

OrderList Customer::getOrders()
{
	return orders;
}

void Customer::AddOrder(Order ord)
{
	orders.AddOrder(ord);
}

void Customer::UpdateOrders(string bookName, int number)
{
	orders.UpdateOrder(bookName, number);
}

void Customer::CancelOrder(string bookName)
{
	orders.CancelOrder(bookName);
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

bool Customer::operator==(const Customer& other) const
{
	return (name == other.name);
}

bool Customer::operator!=(const Customer& other) const
{
	return (name != other.name);
}