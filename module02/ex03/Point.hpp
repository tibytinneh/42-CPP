#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();							  // default constructor
	Point(const float x, const float y);  // constructor with float
	Point(const Point &other);			  // copy constructor
	Point &operator=(const Point &other); // copy assignment operator
	~Point();							  // destructor

	Fixed getX() const;
	Fixed getY() const;
};

#endif
