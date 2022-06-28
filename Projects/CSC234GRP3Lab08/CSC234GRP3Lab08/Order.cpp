/**
 * \author Ocea' Ellis
 * \date 4/30/2022
 * \description Order class to contain information of customer orders and some operations
 */

#include "Order.h"
#include <iomanip>
#include <iostream>

using std::endl;
using std::setw;
using std::right;


//friend
ostream& operator<<(ostream& osObj, const Order& order)
{
	//format for printing
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	osObj <<
		setw(10) << std::left << "Title: " << setw(30) << right << order.bookTitle << '\n' <<
		setw(10) << std::left << "Unit Price: $" << setw(30) << right << std::fixed << order.unitPrice << '\n' <<
		setw(10) << std::left << "Number: " << setw(30) << right << order.number << '\n';
	return osObj;
}


//constructors
Order::Order() : bookTitle(""), unitPrice(0.0), number(0)
{
}

Order::Order(string title, double price, int num) : bookTitle(title), unitPrice(price), number(num)
{
}


//getters and setters
void Order::setNumber(int num)
{
	number = num;
}

string Order::getTitle()
{
	return bookTitle;
}

double Order::getPrice()
{
	return unitPrice;
}

int Order::getNumber()
{
	return number;
}


//member functions
bool Order::checkTitle(string name)
{
	if (name == bookTitle) {
		return true;
	}
		return false;

}

double Order::CalculateCost()
{
	const double total = unitPrice * number;

	return total;
}


//operator overloading
bool Order::operator==(const Order& order) const
{
	return (bookTitle == order.bookTitle && unitPrice == order.unitPrice
		&& number == order.number);
}

bool Order::operator!=(const Order& order) const
{
	return (bookTitle != order.bookTitle || unitPrice != order.unitPrice
		|| number != order.number);
}
