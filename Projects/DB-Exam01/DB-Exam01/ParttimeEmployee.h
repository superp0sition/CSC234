#pragma once
#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"

using std::string;

class ParttimeEmployee : public Employee
{
public:
	ParttimeEmployee(string name, string title, string email, float wage, int hours);
	void displayEmployee();
private:
	float wage; // low precision floating point since you only need accuracy to two decimals 
	int hours; // int because we're only counting hours instead of full time spent
};

#endif
