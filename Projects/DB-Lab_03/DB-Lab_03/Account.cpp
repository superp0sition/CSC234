#include "Account.h"

Account::Account()
{
	balance = 0;
	_c = NULL;
	id = "0000";
}

Account::Account(double balance, Customer* _c, string id)
{
	this->balance = balance;
	this->_c = _c;
	this->id = id;
}

void Account::display()
{
	std::cout << "Account ID: " << id << std::endl << *_c << "Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl; // \nInterest rate: %.2f\nInterest: $%.2f
}

double Account::get_balance()
{
	return balance;
}

void Account::set_balance(double bal)
{
	balance = bal;
}

bool Account::deposit(double amount)
{
	if (amount > 0) {
		balance += amount;
		return true;
	}
	return false;
}

bool Account::withdraw(double amount)
{
	if (amount > 0 && amount < balance) {
		balance -= amount;
		return true;
	}
	return false;
}

Customer Account::getCus()
{
	return *_c;
}
