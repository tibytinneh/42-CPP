#include "Fixed.hpp"

/* <---Default constructor---> initializes _fixedPointValue to 0 with member initializer list*/
Fixed::Fixed() : _fixedPointValue(0)
{
}

// int constructor
Fixed::Fixed(const int value)
{
	_fixedPointValue = value << _fractionalBits;
}

// float constructor
Fixed::Fixed(const float value)
{
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

/* <---Copy constructor---> */
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
}

/* <---Destructor---> */
Fixed::~Fixed()
{
}
/* <---Comparison Operators---> */
bool Fixed::operator>(const Fixed &other) const
{
	return getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
	return getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return getRawBits() != other.getRawBits();
}

/* <---Arithmetic Operators---> */
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((getRawBits() * other.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((getRawBits() << _fractionalBits) / other.getRawBits());
	return result;
}

/* <---Increment/Decrement Operators---> */
Fixed &Fixed::operator++()
{ // Prefix increment (++a)
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int)
{ // Postfix increment (a++)
	Fixed temp = *this;
	setRawBits(getRawBits() + 1);
	return temp;
}

Fixed &Fixed::operator--()
{ // Prefix decrement (--a)
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int)
{ // Postfix decrement (a--)
	Fixed temp = *this;
	setRawBits(getRawBits() - 1);
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
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// overload `<<` to print out floating-point representation
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{

	out << fixed.toFloat();
	return out;
}
