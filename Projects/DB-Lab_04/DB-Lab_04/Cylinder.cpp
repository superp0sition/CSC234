#include "Cylinder.h"

// Function descriptions were (mostly) copied from lab document

ostream& operator<<(ostream& output, const Cylinder& c) {
    output << "Radius: " << c.radius << " Height: " << c.height;
    return output;
}

istream& operator>>(istream& input, Cylinder& c) {
    input >> c.radius >> c.height;
    return input;
}

Cylinder::Cylinder() : radius(0), height(0) { }

Cylinder::Cylinder(const double r, const double h) : radius(r), height(h) { }

// Assign cylinder2’s radius to cylinder1’s radius and assign cylinder2’s height to cylinder1’s height. 
const Cylinder& Cylinder::operator=(const Cylinder& c) {
    if (this != &c) {
        radius = c.radius;
        height = c.height;
    }

    return *this;
}

// Define prefix increment operator.
Cylinder& Cylinder::operator++() {
    radius++;
    height++;
    return *this;
}

// Define postfix increment operator.
Cylinder Cylinder::operator++(int) {
    Cylinder temp = *this;
    ++* this;
    return temp;
}

// Return a new Cylinder object by adding two cylinder’s radius and adding two cylinder’s height.
Cylinder Cylinder::operator+(const Cylinder& c) const {
    Cylinder cy;

    cy.radius = this->radius + c.radius;
    cy.height = this->height + c.height;

    return cy;
}

// Return a new Cylinder object by subtracting cylinder2’s radius from cylinder1’s radius and subtracting cylinder2’s height from cylinder1’s height.
Cylinder Cylinder::operator-(const Cylinder& c) const {
    Cylinder cy;
    double tempR, tempH;
    tempR = radius - c.radius;
    tempH = height - c.height;
    cy.radius = tempR > 0 ? tempR : 1;
    cy.height = tempH > 0 ? tempH : 1;

    return cy;
}
// Return a new Cylinder multiplying the radii and heights of both Cylinders
Cylinder Cylinder::operator*(const Cylinder& c) const {
    Cylinder cy;

    cy.radius = this->radius * c.radius;
    cy.height = this->height * c.height;

    return cy;
}

// Return a new Cylinder by dividing the radius of Cylinder1 by Cylinder2 and the height of Cylinder1 by Cylinder2
Cylinder Cylinder::operator/(const Cylinder& c) const {
    Cylinder cy;

    cy.radius = this->radius / c.radius;
    cy.height = this->height / c.height;

    return cy;
}

// Return true if cylinder1’s radius equal to cylinder2’s radius, and cylinder1’s height equal to cylinder2’s height, otherwise, return false.
bool Cylinder::operator==(const Cylinder& c) const
{
    return this->height == c.height && this->radius == c.radius;
}

// Return true if cylinder1’s radius not equal to cylinder2’s radius, and cylinder1’s height not equal to cylinder2’s height, otherwise, return false.
bool Cylinder::operator!=(const Cylinder& c) const
{
    return this->height != c.height && this->radius != c.radius;
}

// Return true if cylinder1’s radius is less than cylinder2’s radius, and cylinder1’s height is less than cylinder2’s height, otherwise, return false.
bool Cylinder::operator<(const Cylinder& c) const
{
    return this->height < c.height && this->radius < c.radius;
}

// Return true if cylinder1’s radius is <= cylinder2’s radius, and cylinder1’s height is <= cylinder2’s height, otherwise, return false.
bool Cylinder::operator<=(const Cylinder& c) const
{
    return this->height <= c.height&& this->radius <= c.radius;
}

// Return true if cylinder1’s radius is greater than cylinder2’s radius, and cylinder1’s height is greater than cylinder2’s height, otherwise, return false.
bool Cylinder::operator>(const Cylinder& c) const
{
    return this->height > c.height&& this->radius > c.radius;
}

// Return true if cylinder1’s radius is >= cylinder2’s radius, and cylinder1’s height is >= cylinder2’s height, otherwise, return false.
bool Cylinder::operator>=(const Cylinder& c) const
{
    return this->height >= c.height && this->radius >= c.radius;
}


