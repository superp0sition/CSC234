#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using std::string;

class Employee
{
public:
	Employee(string name, string title, string email);
	virtual void displayEmployee(); // abstract function to display data about employees
	friend std::ostream& operator<<(std::ostream& out, const Employee& emp); // tell function how to display this class
private:
	string name;
	string title;
	string email;
};

#endif