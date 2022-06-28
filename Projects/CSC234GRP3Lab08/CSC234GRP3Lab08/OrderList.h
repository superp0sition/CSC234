/**
 * \author Larry Webb
 * \date 4/30/2022
 * \description OrderList class inheriting from LinkedList to store order variables
 */

#pragma once
#ifndef ORDERLIST_H
#define ORDERLIST_H
#include "linkedList.h";
#include "Order.h"
#include <fstream>

class OrderList :
	public linkedListType<Order>
{
	friend ostream& operator<<(ostream&, const OrderList&);
public:
	void AddOrder(Order&);
	void UpdateOrder(string, int);
	void CancelOrder(string);
	double CalculateSubtotal();
	void UpdateDataFile(ofstream&);
private:
	void SearchOrderList(string title, bool& found, nodeType<Order>*& current) const;
};



#endif