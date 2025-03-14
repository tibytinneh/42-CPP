#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> //for roundf()

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();				   // default constructor
	Fixed(const int value);	   // int constructor
	Fixed(const float value);  // float constructor
	Fixed(const Fixed &other); // copy constructor

	~Fixed(); // destructor

	Fixed &operator=(const Fixed &other); // copy assignment constructor

	/* <---member functions---> */
	float toFloat(void) const; // conver fixed-point to float
	int toInt(void) const;	   // convert fixed-point to int
	int getRawBits(void) const;		// member function
	void setRawBits(int const raw); // member function
};

	/* <---Overloaded stream insertion operator---> */
	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif // FIXED_HPP
