#pragma once
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
public:
	CheckingAccount(double bal, Customer* _c, string id, float fee);
	bool deposit(double amount) override; // overrides the function from Account, adding a check by applying the fee
	bool withdraw(double amount) override; // same as above
	void display() override; // re-implements the function from account to add additional members from this class

private:
	float fee;
};

#endif // !CHECKINGACCOUNT_H
