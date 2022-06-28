#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <exception>
#include <string>
#include <iostream>
#include <iomanip>

class account
{
public:
	account(int identifier, const char* name, double bal);
	void withdraw(double amount);
	void deposit(double amount);
	void display_account();

private:
	int identifier;
	const char* name; // name defined using c friendly type
	double balance;

};

class accountException : public std::exception
{
public:
	accountException() : excep("Invalid transaction")
	{
	}

	accountException(const std::string& c)
	{
		excep = "Invalid " + c + " transaction";
	}
	const char* what() const noexcept override // returns c string containing error message
	{
		return excep.c_str();
	}
private:
	std::string excep; // stored as a string to be modified (didn't want to use a char[])
};

#endif
