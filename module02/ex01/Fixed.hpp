#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> //for roundf()

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
	Fixed();				   // default constructor
	Fixed(const int value);	   // int constructor
	Fixed(const float value);  // float constructor
	Fixed(const Fixed &other); // copy constructor

	~Fixed(); // destructor

	Fixed &operator=(const Fixed &other); // copy assignment constructor

	/* <---member functions---> */
	float toFloat(void) const;		// conver fixed-point to float
	int toInt(void) const;			// convert fixed-point to int
	int getRawBits(void) const;		// getter
	void setRawBits(int const raw); // setter

	/* <---Overloaded stream insertion operator---> */
	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif // FIXED_HPP
