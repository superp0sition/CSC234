#pragma once

#include <string>
#include <iostream>

using namespace std;

class Order {

	friend ostream& operator<< (ostream& osObj, const Order& order);

private:
	string bookTitle;
	double unitPrice;
	int number;

public:
	Order();
	Order(string title, double price, int num);
	bool checkTitle(string name);
	double calculateCost();
	void setNumber(int num);
	string getTitle();
	double getPrice();
	int getNumber();
	bool operator==(const Order& order) const;
	bool operator!=(const Order& order) const;
};