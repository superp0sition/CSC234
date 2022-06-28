#include "FulltimeEmployee.h"
#include <iomanip>

FulltimeEmployee::FulltimeEmployee(string name, string title, string email, float salary) : Employee(name, title, email),
	salary(salary)
{

}

void FulltimeEmployee::displayEmployee()
{
	std::cout << "Fulltime Employee" << std::endl << *this << "Salary: $" << std::setprecision(2) << std::fixed << salary << std::endl;
}


