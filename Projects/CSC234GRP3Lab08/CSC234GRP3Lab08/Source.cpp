#include <iomanip>

#include "OrderList.h"
#include "CustomerList.h"
#include <iostream>

using std::getline;
using std::cout;
using std::cin;

void LoadCustomers(ifstream& f, CustomerList& list)
{
	string name;
	string address;
	string email;

	string title;
	string price;
	string quantity;
	getline(f, name);
	while (!f.eof())
	{
		name.erase(0, 1);
		getline(f, address);
		getline(f, email);
		const auto orders = new OrderList();
		while(getline(f, title) && title[0] != '%' && !f.eof())
		{
			getline(f, price);
			getline(f, quantity);
			const auto order = new Order(title, stod(price), stoi(quantity));
			orders->AddOrder(*order);
		}
		const auto customer = new Customer(name, address, email, *orders);
		list.AddCustomer(*customer);
		name = title;
	}
}

int selectMenu()
{
	std::cout << '\n' << "Please select one of the following actions" << '\n'
	<< "1. Place an order." << '\n'
	<< "2. Update an order." << '\n'
	<< "3. Cancel an order." << '\n'
	<< "4. Print all orders." << '\n'
	<< "5. Checkout orders." << '\n'
	<< "6. Exit" << std::endl;
	int input;
	cin >> input;
	return input;
}

void PlaceOrder(CustomerList& customers)
{
	char inp;
	do
	{
		string name;
		const auto c = new Customer();
		std::cout << "Enter customer name: ";
		cin.ignore(100, '\n');
		getline(cin, name);

		if (customers.SearchCustomerByName(name))
		{
			std::cout << "Existing customer." << '\n';
			*c = customers.getCustomerByName(name);
		}
		else
		{
			std::cout << "New customer." << '\n';
			string address;
			string email;
			cout << "Enter customer address: ";
			getline(cin, address);
			cout << "Enter customer email: ";
			getline(cin, email);
			const auto orders = new OrderList();
			*c = Customer(name, address, email, *orders);
			customers.AddCustomer(*c);
		}
		string bookTitle;
		string price;
		string number;
		cout << "Enter the book title: ";
		getline(cin, bookTitle);
		cout << "Enter the price of the book: "; cin >> price;
		cout << "Enter the number of books: "; cin >> number;
		const auto o = Order(bookTitle, stod(price), stoi(number));
		c->AddOrder(o);

		cout << '\n' << "Would you like to place another order (y/n) ";
		cin >> inp;

	} while (inp == 'y');
}

void UpdateOrder(CustomerList& customers)
{
	string name;
	std::cout << "Enter customer name: ";
	cin.ignore(100, '\n');
	getline(cin, name);
	if (!customers.SearchCustomerByName(name))
	{
		cout << "Customer does not exist." << '\n';
		return;
	}
	Customer c = customers.getCustomerByName(name);
	customers.UpdateCustomer(c);
}

void CancelOrder(CustomerList& customers)
{
	string name;
	string bookTitle;
	cout << "Enter customer name: ";
	cin.ignore(100, '\n');
	getline(cin, name);
	cout << "Enter the book title to be canceled: ";
	getline(cin, bookTitle);
	if (!customers.SearchCustomerByName(name))
	{
		cout << "Customer does not exist." << '\n';
		return;
	}
	Customer c = customers.getCustomerByName(name);
	c.getOrders().CancelOrder(bookTitle);
}

void PrintOrders(CustomerList& customers) //double check
{
	//prints all of the orders in CustomerList
	cout << customers << endl;
}
void CheckoutOrders(CustomerList& customers)
{
	//searches for a name in CustomerList
	//if found, prints information, order, subtotal, tax, and total
	//else, displays an error
	string name;
	bool found;
	cout << "Enter customer name: ";
	cin.ignore(100, '\n');
	getline(cin, name);
	found = customers.SearchCustomerByName(name);
	if (found) {
		auto custName = customers.getCustomerByName(name);
		auto subtotal = custName.getOrders().CalculateSubtotal();
		cout << custName << '\n' <<
			setw(20) << "Subtotal: $" << setw(30) << right << subtotal << '\n' <<
			setw(20) << "Tax: $" << setw(20) << right << subtotal*0.07 << '\n' <<
			setw(20) << "Total payment: $" << right << (subtotal * 0.07) + subtotal << '\n';
	}
	else {
		cout << "Name Not Found.";
	}
}
void UpdateDatafile(CustomerList& customers, ofstream& output) // also double check
{
	//creates an output and updates the data file entirely
	customers.UpdateDataFile(output);
}

int main()
{
	cout << "Welcome to Wake Bookstore!" << '\n';

	const auto customers = new CustomerList();
	string filename = "orders.txt";
	ifstream file(filename);
	LoadCustomers(file, *customers);

	cout << "All customers and orders are loaded." << '\n';

	int inp = 0;
	while (inp != 6)
	{
		inp = selectMenu();
		switch(inp)
		{
		case 1:
			PlaceOrder(*customers);
			break;
		case 2:
			UpdateOrder(*customers);
			break;
		case 3:
			CancelOrder(*customers);
			break;
		case 4:
			PrintOrders(*customers);
			break;
		case 5:
			CheckoutOrders(*customers);
			break;
		case 6:
			std::cout << "Thanks for shopping at Wake Bookstore" << std::endl;
			break;
		default:
			std::cout << "Please enter a valid option" << std::endl;
			break;

		}
		ofstream ofile(filename, ios::trunc);
		UpdateDatafile(*customers, ofile);
		
	}
	file.close();
	return 0;
}