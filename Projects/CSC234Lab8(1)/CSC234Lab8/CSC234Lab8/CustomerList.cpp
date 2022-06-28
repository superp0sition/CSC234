#include <iostream>
#include <string>
#include "CustomerList.h"
#include "linkedList.h"
using namespace std;

//bool CustomerList::SearchCustomer(Customer customerObj) const
//{
//    return search(customerObj);
//}

bool CustomerList::SearchCustomerByName(string name) const
{
    nodeType<Customer>* current;
    current = first;
    bool found = false;
    while (current != nullptr)
    {
        if (current->info.getCustomerName() == name)
            found = true;
        current = current->link;
    }
    return found;
}

Customer CustomerList::getCustomerByName(string name) const
{
    nodeType<Customer>* current;
    current = first;
    while (current != nullptr)
    {
        if (current->info.getCustomerName() == name)
            return current->info;
        current = current->link;
    }
}

void CustomerList::AddCustomer(Customer& newCustomer)
{
    insertLast(newCustomer);
}

//void CustomerList::PrintCustomers() const
//{
//    print();
//}

void CustomerList::UpdateCustomer(Customer& cust)
{
    nodeType<Customer>* current;
    current = first;
    while (current != nullptr)
    {
        if (current->info.getCustomerName() == cust.getCustomerName())
            current->info = cust;
        current = current->link;
    }
}

void CustomerList::UpdateDataFile(ofstream& outFile)
{
    nodeType<Customer>* current;
    current = first;
    while (current != nullptr)
    {
        outFile << "%" + current->info.getCustomerName() << '\n'
            << current->info.getAddress() << '\n'
            << current->info.getEmail() << '\n';
        current->info.getOrders().UpdateDataFile(outFile);
        current = current->link;
    }
}

ostream& operator<<(ostream& osObject, const CustomerList& CustomerListObj)
{
    nodeType<Customer>* current;
    current = CustomerListObj.first;
    while (current != nullptr)
    {
         osObject << current->info;
         current = current->link;
    }
    return osObject;
}

