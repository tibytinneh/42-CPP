#include "Fixed.hpp"

/* <---Default constructor---> initializes _fixedPointValue to 0 with member initializer list*/
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << C_BLUE << "Default constructor called" << C_DEFAULT << std::endl;
}

// int constructor
Fixed::Fixed(const int value)
{
	std::cout << C_BLUE << "Int constructor called" << C_DEFAULT << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

// float constructor
Fixed::Fixed(const float value)
{
	std::cout << C_BLUE << "Float constructor called" << C_DEFAULT << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

/* <---Copy constructor---> */
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
	std::cout << C_YELLOW << "Copy constructor called" << C_DEFAULT << std::endl;
}

/* <---Destructor---> */
Fixed::~Fixed()
{
	std::cout << C_RED << "Destructor called" << C_DEFAULT << std::endl;
}

/* <---Comparison Operators---> */
bool Fixed::operator>(const Fixed &other) const { return _fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed &other) const { return _fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed &other) const { return _fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed &other) const { return _fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed &other) const { return _fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed &other) const { return _fixedPointValue != other._fixedPointValue; }

/* <---Arithmetic Operators---> */
Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

/* <---Increment/Decrement Operators---> */

Fixed &Fixed::operator++()
{
	_fixedPointValue++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_fixedPointValue++;
	return temp;
}
Fixed &Fixed::operator--()
{
	_fixedPointValue--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_fixedPointValue--;
	return temp;
}

/* <---Public overloaded member functions---> */
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return a > b ? a : b; }

/* <---member functions---> */

float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

// overload `<<` to print out floating-point representation
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{

	out << fixed.toFloat();
	return out;
}
