#include "FulltimeEmployee.h"
#include "ParttimeEmployee.h"

// provided in project docx
int main()
{
	// create FulltimeEmployee object
	FulltimeEmployee emp1("Mary Davis", "Faculty", "md@waketech.edu", 60000.00);
	// create ParttimeEmployee object
	ParttimeEmployee emp2("Tom Fox", "Secretary", "tf@waketech.edu", 20.00, 30);
	// create an array of base class Employee pointers   
	Employee* employees[2];
	// assign the address of the two employee objects in the array
	// both emp1 and emp2 are also Employee objects
	employees[0] = &emp1;
	employees[1] = &emp2;
	// implement dynamic binding and polymorphism
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Employee " << i + 1 << std::endl;
		// the same function call will generate different results depend on 
		// what employee object pointed to by the Employee pointer
		employees[i]->displayEmployee();
		std::cout << std::endl;
	}
	return 0;
}

// I was half hoping the name would be user input so I could show that I finally learned getline for cin after forgetting it twice