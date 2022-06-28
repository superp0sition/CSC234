#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double bal, Customer* _c, string id, float fee) : Account{ bal, _c, id }
{
	this->fee = fee;
}

bool CheckingAccount::deposit(double amount)
{
	return Account::deposit(amount - fee);
}

bool CheckingAccount::withdraw(double amount)
{
	return Account::withdraw(amount + fee);
}

void CheckingAccount::display()
{
	std::cout << "\n ---- Checking Account Details ---- " << std::endl;
	Account::display();
	std::cout << "Transaction fee: $" << std::fixed << std::setprecision(2) << fee << std::endl;
}

