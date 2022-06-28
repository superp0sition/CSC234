#include<iostream>
#include<iomanip>
#include<string>
#include"Order.h"
using namespace std;

Order::Order()
{
	bookTitle = "";
	unitPrice = 0.0;
	number = 0;
}

Order::Order(string _bookTitle, double _unitPrice, int _number)
{
	bookTitle = _bookTitle;
	unitPrice = _unitPrice;
	number = _number;
}

bool Order::checkTitle(string title)
{
	return(bookTitle == title);
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

double Order::CalculateCost()
{
	return unitPrice * number;
}

void Order::setNumber(int _number)
{
	number = _number;
}

bool Order::operator==(const Order& other) const
{
	return (bookTitle == other.bookTitle);
}

bool Order::operator!=(const Order& other) const
{
	return (bookTitle != other.bookTitle);
}

ostream& operator<<(ostream& osObject, const Order& OrderObj)
{
	osObject << setw(20) << left << "Title: " << right << setw(30) << OrderObj.bookTitle << "\n"
		<< setw(20) << left << "Unit Price: $" << right<< setw(30) << fixed << setprecision(2) << OrderObj.unitPrice << "\n"
		<< setw(20) << left << "Number: " << right << setw(30) << OrderObj.number << endl;
	return osObject;
}
