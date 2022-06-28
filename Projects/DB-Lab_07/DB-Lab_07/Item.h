#pragma once
#include <string>
#include <iomanip>
#include <ios>
#include <iostream>
#include <utility>

class Item
{
public:
	Item();
	Item(std::string, std::string, int, double);
	std::string getID();
	std::string getName();
	int getNumber();
	double getPrice();
	void setNumber(int);
	void printItem();
private:
	std::string itemID;
	std::string itemName;
	int NumberInStore;
	double unitPrice;
};
