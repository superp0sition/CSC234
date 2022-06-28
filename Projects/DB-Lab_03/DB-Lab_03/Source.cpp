#include <iostream>
#include <iomanip>
#include "Customer.h"
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

/**
 * \brief Displays the main menu with the user input prompt
 */
void dispMenu();

int main()
{
	int selection = 0;
	string firstName = "";
	string lastName = "";
	string address = "";
	string email = "";
	int id = 1; // int for iterating id in constructor later
	double amount = 0.0;
	// input user’s information
	cout << "Enter your first name: "; cin >> firstName;
	cout << "Enter your last name: "; cin >> lastName;
	cout << "Enter your address: "; cin >> address;
	cout << "Enter your email: "; cin >> email;

	Customer* me = new Customer(firstName, lastName, address, email);

	// create CheckingAccount object
	CheckingAccount myCheckingAccount(0.0, me, string(4,48 + id++), 5);// call constructor, id entered is string using the repeating character constructor

	// create SavingsAccount object 
	SavingsAccount mySavingsAccount(0.0, me, string(4, 48 + id++), 0.02); 

	cout << "Your checking account and savings account are created successfully. " << endl << endl;
	Account* myAccounts[2]; // moved from template since it was necessary before to do option 1 before any other function
	myAccounts[0] = &myCheckingAccount;
	myAccounts[1] = &mySavingsAccount;

	do
	{
		dispMenu(); // display menu
		cin >> selection;
		switch (selection)
		{
		case 1:
			for (int i = 0; i < 2; i++)
				myAccounts[i]->display();
			cout << endl;
			break;
		case 2:
			// deposit to checking account
			cout << "How much would you like to deposit? "; cin >> amount;
			if (myAccounts[0]->deposit(amount))
			{
				std::cout << "You deposited $" << std::fixed << std::setprecision(2) << amount << std::endl;
			}
			else 
			{
				std::cout << "You cannot deposit 0 or a negative amount of money." << std::endl;
				break;
			}
			std::cout << "Your balance is now $" << std::fixed << std::setprecision(2) << myAccounts[0]->get_balance() << std::endl;
			break;
		case 3:
			// deposit to savings account
			cout << "How much would you like to deposit? "; cin >> amount;
			if (myAccounts[1]->deposit(amount))
			{
				std::cout << "You deposited $" << std::fixed << std::setprecision(2) << amount << std::endl;
			}
			else
			{
				std::cout << "You cannot deposit 0 or a negative amount of money." << std::endl;
				break;
			}
			std::cout << "Your balance is now $" << std::fixed << std::setprecision(2) << myAccounts[1]->get_balance() << std::endl;
			break;
		case 4:
			// withdraw from checking account
			cout << "How much would you like to withdraw? "; cin >> amount;
			if (myAccounts[0]->withdraw(amount))
			{
				std::cout << "You withdrew $" << std::fixed << std::setprecision(2) << amount << std::endl;
			}
			else
			{
				std::cout << "You cannot withdraw 0 or a negative amount of money and you must have enough money in the account." << std::endl;
				break;
			}
			std::cout << "Your balance is now $" << std::fixed << std::setprecision(2) << myAccounts[0]->get_balance() << std::endl;
			break;
		case 5:
			// withdraw from savings account
			cout << "How much would you like to withdraw? "; cin >> amount;
			if (myAccounts[1]->withdraw(amount))
			{
				std::cout << "You withdrew $" << std::fixed << std::setprecision(2) << amount << std::endl;
			}
			else
			{
				std::cout << "You cannot withdraw 0 or a negative amount of money and you must have enough money in the account." << std::endl;
				break;
			}
			std::cout << "Your balance is now $" << std::fixed << std::setprecision(2) << myAccounts[1]->get_balance() << std::endl;
			break;
		case 6:
			// transfer money from checking account to savings account
			cout << "How much would you like to transfer? "; cin >> amount;
			if (myAccounts[0]->get_balance() >= 5)
			{
				myAccounts[0]->withdraw(amount);
				myAccounts[1]->deposit(amount);
			}
			else
				cout << "Transfer could not be completed, check your balance\n";
			break;
		case 7:
			// transfer money from savings account to checking account
			cout << "How much would you like to transfer? "; cin >> amount;
			if (myAccounts[0]->get_balance() >= 5)
			{
				myAccounts[1]->withdraw(amount);
				myAccounts[0]->deposit(amount);
			}
			else
				cout << "Transfer could not be completed, check your balance\n";
			break;
		default:
			cout << "Invalid selection." << endl;
			break;
		}

		// display the menu and ask for next selection from user
	} while (selection != 8);
	cout << "Thanks for using Bank of Wake!" << endl;
	return 0;
}

void dispMenu() 
{
	cout << // menu text with selection prompt end since it should always be repeated
		R"(1. Display Accounts
2. Deposit to checking account
3. Deposit to savings account
4. Withdraw from checking account.
5. Withdraw from savings account.
6. Transfer money from checking account to savings account.
7. Transfer money from savings account to checking account.
8. Exit)" << endl << "Enter your service selection: ";
}