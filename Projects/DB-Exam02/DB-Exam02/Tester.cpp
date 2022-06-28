#include <iostream>
#include "Mathematics.h"
#include "ZeroCheck.h"

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

/**
 * \brief Parameterized constructor for a Mathematics object, assigns values to both data members
 * \param v1 The first data member 
 * \param v2 The second data member
 */
template<class T>
Mathematics<T>::Mathematics(T v1, T v2) : v1(v1), v2(v2)
{
}

/**
 * \brief Adds the two data variables of a Mathematics object
 * \return Result of the addition 
 */
template <class T>
T Mathematics<T>::addition() const
{
	return v1 + v2;
}

/**
 * \brief Substracts the second data member from the first of a Mathematics object
 * \return Result of the subtraction
 */
template <class T>
T Mathematics<T>::subtraction() const // forgot to spellcheck this function, called it "substraction" at first
{
	return v1 - v2;
}

/**
 * \brief Multiplies the data members of a Mathematics object
 * \return Result of the multiplication
 */
template <class T>
T Mathematics<T>::multiplication() const
{
	return v1 * v2;
}

/**
 * \brief Divides the first data member by the second of a Mathematics object
 * \throws ZeroCheck Exception thrown if divisor is 0
 * \return Result of the division
 */
template <class T>
T Mathematics<T>::division() const
{
	if (v2 == 0)
		throw ZeroCheck();
	return v1 / v2;
}

/**
 * \brief Overloads output operator for a Mathematics object, calls various members for resultant values
 * \tparam T The data-type of the members of a Mathematics object
 * \param os The stream to be used
 * \param obj A reference to the object to be output
 * \return The resulting output stream
 */
template<class T>
std::ostream& operator<<(std::ostream& os, Mathematics<T>& obj)
{
	os << "Results of the calculations for " << obj.v1 << " and " << obj.v2 << endl;
	os << "The sum is " << obj.addition() << endl;
	os << "The difference is " << obj.subtraction() << endl;
	os << "The product is " << obj.multiplication() << endl;
	try
	{
		os << "The quotient is " << obj.division() << endl;
	}
	catch (ZeroCheck &e)
	{
		os << e.what() << endl;
	}
	return os;
}
