#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "OrderList.h"
#include "CustomerList.h"
#include "Customer.h"
#include "Order.h"
#include <string>
using namespace std;

void LoadCustomers(ifstream&, CustomerList&);
int selectMenu();
void PlaceOrder(CustomerList&);
void UpdateOrder(CustomerList&);
void CancelOrder(CustomerList&);
void PrintOrders(CustomerList&);
void CheckoutOrders(CustomerList&);
void UpdateDatafile(CustomerList&);

int main()
{
    ifstream inFile;
    int selection = 0;
    Customer customerObj;
    CustomerList customers;
    OrderList myList;
    cout << "Welcome to Wake Booktore!" << endl;
    inFile.open("BookOrders.txt");
    if (!inFile)
    {
        cout << "The input file does not exist. " << endl;
        return 1;
    }
    LoadCustomers(inFile, customers);


    selection = selectMenu();
    while (selection != 6)
    {
        switch (selection)
        {
        case 1:
            PlaceOrder(customers);
            break;
        case 2: 
            UpdateOrder(customers);
            break;
        case 3: 
            CancelOrder(customers);
            break;
        case 4:
            PrintOrders(customers);
            break;
        case 5:
            CheckoutOrders(customers);
            break;
        }
        selection = selectMenu();
    }
    cout << "Thanks for shopping at Wake Bookstore!" << endl;
	return 0;
}

void LoadCustomers(ifstream& inFile, CustomerList& customerList)
{
    string customerName = "";
    string address = "";
    string email = "";
    string bookName = "";
    double unitPrice = 0.0;
    int number = 0;
    Customer thisCustomer;
    while (inFile && inFile.peek() == '%')
    {
        Order thisOrder;
        OrderList thisOrderList;
        getline(inFile, customerName);
        customerName = customerName.substr(1, customerName.length());
        getline(inFile, address);
        getline(inFile, email);
        while (inFile && inFile.peek() != '%' && inFile.peek() != EOF)
        {
            getline(inFile, bookName);
            inFile >> unitPrice;
            inFile >> number;
            inFile.ignore(100, '\n');
            thisOrder = Order(bookName, unitPrice, number);
            thisOrderList.AddOrder(thisOrder);
        }
        thisCustomer = Customer(customerName, address, email, thisOrderList);
        thisOrderList.destroyList();
        customerList.AddCustomer(thisCustomer);
    }
    cout << "All customers and orders are loaded." << endl << endl;
    inFile.close();
}

int selectMenu()
{
    int selection = 0;
    cout << "Please select one of the following action: " << endl;
    cout << "1: Place an order." << endl;
    cout << "2: Update an order." << endl;
    cout << "3: Cancel an order." << endl;
    cout << "4: Print all orders." << endl;
    cout << "5: Checkout orders." << endl;
    cout << "6: Exit" << endl;
    cin >> selection;
    return selection;
} 

void PlaceOrder(CustomerList& customers)
{
    string name = "";
    string address = "";
    string email = "";
    char orderOrNot = ' ';
    string bookName = "";
    double unitPrice = 0.0;
    int number = 0;
    Customer customerObj;
    OrderList myList;
    bool found = false;
    while (true)
    {
        cout << "Enter customer name: ";
        cin.ignore(100, '\n');
        getline(cin, name);
        if (customers.SearchCustomerByName(name))
        {
            customerObj = customers.getCustomerByName(name);
            cout << "Existing customer. " << endl;
            cout << "Enter the book title: ";
            getline(cin, bookName);
            cout << "Enter price of the book: ";
            cin >> unitPrice;
            cout << "Enter number of books: ";
            cin >> number;
            Order myOrder(bookName, unitPrice, number);
            customerObj.AddOrder(myOrder);
            customers.UpdateCustomer(customerObj);
        }
        else
        {
            cout << "New customer." << endl;
            cout << "Enter customer address: ";
            getline(cin, address);
            cout << "Enter customer email: ";
            getline(cin, email);
            customerObj = Customer(name, address, email, myList);
            cout << "Enter the book title: ";
            getline(cin, bookName);
            cout << "Enter price of the book: ";
            cin >> unitPrice;
            cout << "Enter number of books: ";
            cin >> number;
            Order myOrder(bookName, unitPrice, number);
            customerObj.AddOrder(myOrder);
            customers.AddCustomer(customerObj);
        }
        UpdateDatafile(customers);
        cout << "New order is added for customer " << name << "." << endl << endl;;
        cout << "Place another order (y or n)? ";
        cin >> orderOrNot;
        if (tolower(orderOrNot) != 'y')
            break;
    }
}

void UpdateOrder(CustomerList& customers)
{
    string name = "";
    int number = 0;
    Customer customerObj;
    cout << "Enter customer name : ";
    cin.ignore(100, '\n');
    getline(cin, name);
    if (customers.SearchCustomerByName(name))
    {
        customerObj = customers.getCustomerByName(name);
        cout << "Enter the book title to be updated: ";
        getline(cin, name);
        cout << "Enter the number of book to be updated: ";
        cin >> number;
        customerObj.UpdateOrders(name, number);
        customers.UpdateCustomer(customerObj);
        cout << "The order is updated." << endl << endl;
        UpdateDatafile(customers);
    }
    else
        cout << "Custome does not exist." << endl << endl;
}

void CancelOrder(CustomerList& customers)
{
    string name = "";
    Customer customerObj;
    cout << "Enter customer name : ";
    cin.ignore(100, '\n');
    getline(cin, name);
    if (customers.SearchCustomerByName(name))
    {
        customerObj = customers.getCustomerByName(name);
        cout << "Enter the book title to be canceled: ";
        getline(cin, name);
        customerObj.CancelOrder(name);
        customers.UpdateCustomer(customerObj);
        cout << "The order is canceled." << endl << endl;
        UpdateDatafile(customers);
    }
    else
        cout << "Custome does not exist." << endl << endl;
}

void PrintOrders(CustomerList& customers)
{
    cout << customers << endl;
}

void CheckoutOrders(CustomerList& customers)
{
    double subtotal = 0.0;
    double tax = 0.0;
    double total = 0.0;
    string name = "";
    Customer customerObj;
    cout << "Enter customer name : ";
    cin.ignore(100, '\n');
    getline(cin, name);
    if (customers.SearchCustomerByName(name))
    {
        customerObj = customers.getCustomerByName(name);
        subtotal = customerObj.checkoutOrders();
        tax = subtotal * 0.07;
        total = subtotal + tax;
        cout << customerObj << endl;
        cout << setw(20) << left << "Subtotal: $" << setw(30) << right << fixed << setprecision(2) << subtotal << endl;
        cout << setw(20) << left << "Tax: $" << setw(30) << right << fixed << setprecision(2) << tax << endl;
        cout << setw(20) << left << "Total payment: $" << setw(30) << right << fixed << setprecision(2) << total << endl << endl;
    }
    else
        cout << "Custome does not exist." << endl << endl;
}

void UpdateDatafile(CustomerList& customers)
{
    ofstream outFile;
    outFile.open("BookOrders.txt");
    customers.UpdateDataFile(outFile);
    outFile.close();
}