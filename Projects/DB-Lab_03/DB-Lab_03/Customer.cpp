#include "Customer.h"

Customer::Customer(string _first, string _last, string _address, string _email)
{
	this->_first = _first;
	this->_last = _last;
	this->_address = _address;
	this->_email = _email;
}

Customer::Customer(Customer const* _c) 
{
	this->_first = _c->_first;
	this->_last = _c->_last;
	this->_address = _c->_address;
	this->_email = _c->_email;
}

std::ostream& operator<<(std::ostream& out, const Customer& c)
{
	out << "Name: " << c._first << " " << c._last << std::endl << "Address: " << c._address << std::endl << "Email: " << c._email << std::endl;
	// thought I would try something a little different for this lab since I've mostly been relying on printf and not demonstrating this knowledge of c++
	return out;
}