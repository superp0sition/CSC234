#include "OrderList.h"

ostream& operator<<(ostream& outStream, const OrderList& orderOutput)
{
	// TODO: insert return statement here
	/*OrderList tempList;
	tempList = orderOutput;
	for (int i = 0; i <= tempList.length(); i++)
	{
		outStream << tempList.front() << "\n";
		tempList.deleteNode(tempList.front());
	}
	tempList.destroyList();*/
	if (orderOutput.isEmptyList())
	{
		return outStream;
	}
	nodeType<Order>* current;
	current = orderOutput.first;
	while (current != nullptr)
	{
		outStream << current->info;
		current = current->link;
	}
	return outStream;
}

void OrderList::AddOrder(Order& order)
{
	this->insertLast(order);
}

void OrderList::UpdateOrder(string order, int newNumber)
{
	if (this->isEmptyList())
	{
		return;
	}
	nodeType<Order>* current;
	current = first;
	while (current != nullptr && current->info.getTitle() != order)
	{
		current = current->link;
	}
	if (current == nullptr)
	{
		cout << "\nORDER NOT FOUND\n";
	}
	else
	{
		current->info.setNumber(newNumber);
	}
}

void OrderList::CancelOrder(string order)
{
	if (this->isEmptyList())
	{
		return;
	}
	nodeType<Order>* current;
	current = first;
	while (current != nullptr && current->info.getTitle() != order)
	{
		current = current->link;
	}
	if (current == nullptr)
	{
		cout << "\nORDER NOT FOUND\n";
	}
	else
	{
		Order orderToDelete(current->info.getTitle(), current->info.getPrice(), current->info.getNumber());
		this->deleteNode(orderToDelete);
	}
}

double OrderList::CalculateSubtotal()
{
	if (this->isEmptyList())
	{
		return 0;
	}
	double subtotal = 0;
	nodeType<Order>* current;
	current = first;
	while (current != nullptr)
	{
		subtotal = subtotal + (current->info.getPrice() * current->info.getNumber());
		current = current->link;
	}
	return subtotal;
}

void OrderList::UpdateDataFile(ofstream& ofs)
{
	if (this->isEmptyList())
	{
		return;
	}
	if (ofs.is_open())
	{
		nodeType<Order>* current;
		current = first;
		while (current != nullptr)
		{
			ofs << current->info.getTitle() << endl << current->info.getPrice() <<
				endl << current->info.getNumber() << endl;
			current = current->link;
		}
	}
}

void OrderList::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{
}

void OrderList::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{
}
