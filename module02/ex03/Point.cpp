#include "Point.hpp"
#include <iostream>

/* <---Default Constructor---> init x & y to 0*/
Point::Point() : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}
// copy assignment operator
Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

Point::~Point() {}

/* <---Getters---> */
Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}
