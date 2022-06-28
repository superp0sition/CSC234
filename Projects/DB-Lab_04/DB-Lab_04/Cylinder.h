#pragma once
#ifndef CYLINDER_H
#define CYLINDER_H
#include <iostream>

using std::ostream;
using std::istream;

class Cylinder
{
    friend ostream& operator<<(ostream& output, const Cylinder& c);
    friend istream& operator>>(istream& input, Cylinder& c);

public:
	Cylinder();
    Cylinder(const double r, const double h);
    // overload assignment operator
    const Cylinder& operator=(const Cylinder&);
    // overload increment operator
    Cylinder& operator++();
    Cylinder operator++(int);
    // overload relational operators
    Cylinder operator+(const Cylinder& c) const;
    Cylinder operator-(const Cylinder& c) const;
    Cylinder operator*(const Cylinder& c) const;
    Cylinder operator/(const Cylinder& c) const;
    // overload the relational operators
    bool operator==(const Cylinder& c) const;
    bool operator!=(const Cylinder& c) const;
    bool operator<=(const Cylinder& c) const;
    bool operator<(const Cylinder& c) const;
    bool operator>=(const Cylinder& c) const;
    bool operator>(const Cylinder& c) const;
    
private:
	double radius;
	double height;
};

#endif
