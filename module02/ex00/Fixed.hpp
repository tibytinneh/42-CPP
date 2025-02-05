#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define C_RED "\033[31m"
#define C_BLUE "\033[34m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_DEFAULT "\033[0m"

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
