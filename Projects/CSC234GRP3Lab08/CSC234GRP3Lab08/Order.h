/**
 * \author Ocea' Ellis
 * \date 4/30/2022
 * \description Order class to contain information of customer orders and some operations
 */

#pragma once
#ifndef ORDER_H
#define ORDER_H
#include <string>

using std::string;
using std::ostream;

class Order
{
	friend ostream& operator<<(ostream&, const Order&);
public:
	Order();
	Order(string, double, int);
	bool checkTitle(string);
	double CalculateCost();
	void setNumber(int);
	string getTitle();
	double getPrice();
	int getNumber();
	bool operator==(const Order&) const;
	bool operator!=(const Order&) const;
private:
	string bookTitle;
	double unitPrice;
	int number;
};

#endif
