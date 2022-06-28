#pragma once
#include <exception>
#ifndef H_ZEROCHECK
#define H_ZEROCHECK

class ZeroCheck : public std::exception
{
public:
	ZeroCheck() : str("Denominator is 0, invalid division."){} // initialize c-string member
	char const* what() const override
	{
		return str;
	}
private:
	const char* str; // c-string used because that seems to be convention
					 // and there is no need to do operations before it is
					 // defined
};

#endif
