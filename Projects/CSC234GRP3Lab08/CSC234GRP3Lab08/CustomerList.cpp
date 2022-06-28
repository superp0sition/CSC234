/**
 * \author David Badcoe
 * \date 4/30/2022
 * \description LinkedList containing customers with additional functions
 */

#include "CustomerList.h"

#include <iomanip>

/**
 * \brief Adds a customer to the linked list
 * \param c The customer to add
 */
void CustomerList::AddCustomer(Customer& c)
{
	this->insertLast(c);
}

/**
 * \brief Searches for a customer by name
 * \param name Name of the customer to search for
 * \return boolean of whether the customer exists in the list or not
 */
bool CustomerList::SearchCustomerByName(string name) const
{
    auto current = first; // basically copied from the LinkedList search, but using a parameter since I don't think lambda expressions work here
    bool found = false;
    while (current != nullptr && !found)
    {
        if (current->info.getCustomerName() == name)
            found = true;
        else
            current = current->link;
    }
    return found;
}

/**
 * \brief Searches for a customer by name
 * \param name Name of the customer to search for
 * \return The customer object if found
 */
Customer CustomerList::getCustomerByName(string name) const
{
    auto current = first;
    while (current != nullptr && current->info.getCustomerName() != name)
    {
    	current = current->link;
    }
    return current->info; // this can cause an error if not found so SearchCustomerByName should always be used first
}

/**
 * \brief Updates the customer's orders, by prompting the user
 * \param c The customer to be updated
 */
void CustomerList::UpdateCustomer(Customer& c)
{
    string title;
    string number;
    cout << "Enter the book title to be updated: ";
    getline(cin, title);
    cout << "Enter the number of book to be updated: "; cin >> number;
    c.UpdateOrders(title, stoi(number));
}

/**
 * \brief Prints the current information to the datafile
 * \param file The file output to write to
 */
void CustomerList::UpdateDataFile(ofstream& file)
{
    auto current = first;
    while (current != nullptr)
    {
        file << '%' << current->info.getCustomerName() << '\n' << current->info.getAddress() << '\n' << current->info.getEmail() << '\n';
        current->info.getOrders().UpdateDataFile(file);
        current = current->link;
    }
}

/**
 * \brief Output operator overload for the customerlist for user readability
 * \param out Output stream to write to
 * \param c The customerlist that is being read
 * \return Returns the output stream;
 */
ostream& operator<<(ostream& out, const CustomerList& c)
{
    if (c.isEmptyList())
    {
        return out;
    }
    auto current = c.first;
    while (current != nullptr)
    {
        out << current->info << '\n';
        current = current->link;
    }
    return out;
}