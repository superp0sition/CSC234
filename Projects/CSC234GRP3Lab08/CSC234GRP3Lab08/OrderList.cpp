/**
 * \author Larry Webb
 * \date 4/30/2022
 * \description OrderList class inheriting from LinkedList to store order variables
 */

#include "OrderList.h"

#include <iomanip>

 /**
  * \overloaded operator, outputs the contents of the orderlist as strings
  */
ostream& operator<<(ostream& outStream, const OrderList& orderOutput)
{
    if (orderOutput.isEmptyList())
    {
        return outStream;
    }
    nodeType<Order>* current = orderOutput.first;
    while (current != nullptr)
    {
        outStream << current->info;
        current = current->link;
    }
    return outStream;
}

/**
 * \Uses built in linked list function to add an order to end of order list
 */
void OrderList::AddOrder(Order& order)
{
    this->insertLast(order);
}

/**
 * \If list is empty returns, otherwise finds a requested order by title and changes the number of requested books
 */
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

/**
 * \Returns if list is empty, otherwise searches list for an order by title, and deletes the node if found.
 */
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
        this->deleteNode(current->info);
    }
}

/**
 * \Uses a loop to calculate the sum of all order prices.
 */
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

/**
 * \Returns if list is empty, otherwise sends info from each order to an output file stream.
 */
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

/**
 * \Searches the order list for a title.
 */
void OrderList::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{
    current = first;
    while (current != nullptr && !found)
    {
        if (current->info.getTitle() == title)
            found = true;
        else
            current = current->link;
    }
}