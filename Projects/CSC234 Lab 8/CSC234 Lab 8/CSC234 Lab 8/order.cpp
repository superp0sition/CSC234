#include "order.h"
#include <iomanip>


//friend
ostream& operator<<(ostream& osObj, const Order& order)
{
	//format for printing
	osObj << endl;
	osObj << setw(30) << right << "Title: " << order.bookTitle;
	osObj << setw(30) << "Unit Price: $" << right << order.unitPrice;
	osObj << setw(30) << "Number: " << right << order.number;
	osObj << endl;
	
	return osObj;
}


//constructors
Order::Order()
{
	bookTitle = "";
	unitPrice = 0.0;
	number = 0;
}

Order::Order(string title, double price, int num)
{
	bookTitle = title;
	unitPrice = price;
	number = num;
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
	else {
		return false;
	}

}

double Order::calculateCost()
{
	double total = unitPrice * number;

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