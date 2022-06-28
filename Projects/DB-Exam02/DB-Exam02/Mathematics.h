#pragma once
#ifndef H_MATHEMATICS
#define H_MATHEMATICS


template<class T>
class Mathematics
{
public:
	Mathematics(T v1, T v2);
	T addition() const;
	T subtraction() const;
	T multiplication() const;
	T division() const;
	template<class T>friend std::ostream& operator<<(std::ostream&, Mathematics<T>&);
private:
	T v1;
	T v2;
};

#endif