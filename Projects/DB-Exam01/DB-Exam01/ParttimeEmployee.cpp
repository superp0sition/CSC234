#include "ParttimeEmployee.h"

#include <string>
#include <iomanip>

using std::string;

ParttimeEmployee::ParttimeEmployee(string name, string title, string email, float wage, int hours) : Employee(name, title, email),
	wage(wage), hours(hours)
{
}

void ParttimeEmployee::displayEmployee()
{
	std::cout << "Parttime Employee" << std::endl << *this << "Weekly pay: $" << std::setprecision(2) << std::fixed << hours * wage << std::endl;
} // still not a huge fan of iomanip compared to printf
