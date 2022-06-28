#pragma once
#ifndef H_MATHEMATICS
#define H_MATHEMATICS

#include "ZeroCheck.h"

using std::endl;

template<class T>
class Mathematics
{
public:
	/**
	 * \brief Parameterized constructor for a Mathematics object, assigns values to both data members
	 * \param v1 The first data member
	 * \param v2 The second data member
	 */
	Mathematics(T v1, T v2) : v1(v1), v2(v2){}

	/**
	 * \brief Adds the two data variables of a Mathematics object
	 * \return Result of the addition
	 */
	T addition() const { return v1 + v2; }

	/**
	 * \brief Substracts the second data member from the first of a Mathematics object
	 * \return Result of the subtraction
	 */
	T subtraction() const { return v1 - v2; }

	/**
	 * \brief Multiplies the data members of a Mathematics object
	 * \return Result of the multiplication
	 */
	T multiplication() const { return v1 * v2; }

	/**
	 * \brief Divides the first data member by the second of a Mathematics object
	 * \throws ZeroCheck Exception thrown if divisor is 0
	 * \return Result of the division
	 */
	T division() const
	{
		if (v2 == 0)
			throw ZeroCheck();
		return v1 / v2;
	}

	/**
	 * \brief Overloads output operator for a Mathematics object, calls various members for resultant values
	 * \param os The stream to be used
	 * \param obj A reference to the object to be output
	 * \return The resulting output stream
	 */
	friend std::ostream& operator<<(std::ostream& os, Mathematics<T>& obj)
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
private:
	T v1;
	T v2;
};

#endif