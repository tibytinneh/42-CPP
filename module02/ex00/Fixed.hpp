#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();							  // default constructor
	Fixed(const Fixed &other);			  // copy constructor
	Fixed &operator=(const Fixed &other); // copy assignment constructor
	~Fixed();							  // destructor

	int getRawBits(void) const;		// member function
	void setRawBits(int const raw); // member function
};

#endif // FIXED_HPP
