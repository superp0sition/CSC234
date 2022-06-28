#include "SavingsAccount.h"

/**
 * \brief Constructor for savings account
 * \param balance balance of account
 * \param _c customer pointer
 * \param id identifier for the account
 * \param rate rate of interest
 */
SavingsAccount::SavingsAccount(double balance, Customer* _c, string id, double rate) : Account(balance, _c, id)
{
	interestRate = rate;
}

double SavingsAccount::getInterestRate()
{
	return interestRate;
}

double SavingsAccount::calc_interest()
{
	double interest = Account::get_balance() * interestRate;
	Account::set_balance(Account::get_balance() + interest);
	return interest;
}

void SavingsAccount::display()
{
		std::cout << "\n ---- Savings Account Details ---- " << std::endl;
		Account::display();
		std::cout << "Interest Rate: " << std::fixed << std::setprecision(2) << interestRate * 100 << "%" << std::endl;
		std::cout << "Interest: $" << std::fixed << std::setprecision(2) << calc_interest() << std::endl;
}
