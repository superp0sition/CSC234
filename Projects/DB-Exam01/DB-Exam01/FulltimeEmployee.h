#pragma once
#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"

using std::string;

class FulltimeEmployee : public Employee
{
public:
	FulltimeEmployee(string name, string title, string email, float salary);
	void displayEmployee(); // display the class
private:
	float salary;
};

#endif
