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

	/* <---Comparison Operators---> */
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	/* <---Arithmetic Operators---> */
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	/* <---Increment/Decrement Operators---> */

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	/* <---Public overloaded member functions---> */
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	/* <---member functions---> */
	float toFloat(void) const; // conver fixed-point to float
	int toInt(void) const;	   // convert fixed-point to int

	/* <---Overloaded stream insertion operator---> */
	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif // FIXED_HPP
