#include "Employee.h"

Employee::Employee(string name, string title, string email) : name(name), title(title), email(email)
// testing this way of initializing class members since it got recommended by resharper 
{
}

void Employee::displayEmployee()
{
	std::cout << this << std::endl;
}


std::ostream& operator<<(std::ostream& out, const Employee& emp)
{
	out << "Name: " << emp.name << std::endl << "Title: " << emp.title << std::endl << "Email: " << emp.email << std::endl;
	return out;

	// think I want to start moving away from C functions since it's a lot of extra time and text converting my c++ types
}
