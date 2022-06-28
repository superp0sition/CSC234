#include <iostream>
#include <string>
#include "OrderList.h"
#include "linkedList.h"
using namespace std;

void OrderList::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{
    found = false;  
    current = first; 
    while (current != nullptr && !found)     
        if (current->info.checkTitle(title)) 
            found = true;
        else
            current = current->link;   
}

void OrderList::AddOrder(Order& newOrder)
{
    insertLast(newOrder);
}

void OrderList::UpdateOrder(string name, int number)
{
    bool found = false;
    nodeType<Order>* location;
    SearchOrderList(name, found, location); 
    if (found && number > 0)
        location->info.setNumber(number);
    else if(!found)
        cout << "The item " << name << " is not in the shopping cart." << endl;
    else
        cout << "The number " << name << " is invalid." << endl;
}

void OrderList::CancelOrder(string name)
{
    bool found = false;
    nodeType<Order>* location;
    SearchOrderList(name, found, location);
    if (found)
        deleteNode(location->info);
    else 
        cout << "The item " << name << " is not in the shopping cart." << endl;
}

double OrderList::CalculateSubtotal()
{
    double subtotal = 0.0;
    if (!isEmptyList())
    {
        nodeType<Order>* current;
        current = first;
        while (current != nullptr)
        {
            subtotal += current->info.CalculateCost();
            current = current->link;
        }
    }
    return subtotal;
}

//void OrderList::PrintOrders() const
//{
//    print();
//}

void OrderList::UpdateDataFile(ofstream& outFile)
{
    nodeType<Order>* current;
    current = first;
    while (current != nullptr)
    {
        outFile << current->info.getTitle() << '\n'
            << current->info.getPrice() << '\n'
            << current->info.getNumber() << endl;
        current = current->link;
    }
}

ostream& operator<<(ostream& osObject, const OrderList& OrderListObj)
{
    nodeType<Order>* current;
    current = OrderListObj.first;
    while (current != nullptr)
    {
        osObject << current->info;
        current = current->link;
    }
    return osObject;
}