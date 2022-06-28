#include <iostream>
#include "Mathematics.h"

using std::cout;
using std::endl;

int main() // provided in lab document
{
	Mathematics<int> Math1(10, 5);
	Mathematics<double> Math2(5.5, 3.4);
	Mathematics<int> Math3(6, 0);
	cout << "Math 1:" << endl;
	cout << Math1 << endl; // all of these outputs show as errors when editing, but the program compiles and works as intended
	cout << "Math 2:" << endl;
	cout << Math2 << endl;
	cout << "Math 3:" << endl;
	cout << Math3 << endl;
	return 0;
}