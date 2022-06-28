#pragma once
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account 
{
public:
	SavingsAccount(double balance, Customer* _c, string id, double rate);
	/**
	 * \brief Returns the interest rate
	 * \return interestRate
	 */
	double getInterestRate();
	/**
	 * \brief Calculates the interest using the formula Interest = Balance * interestRate
	 * \return returns interest
	 */
	double calc_interest();
	void display() override; // overrides the function adding info from this class including adding the calculated interest
private:
	double interestRate;
};

#endif // !SAVINGSACCOUNT_H