#include "Fixed.hpp"

/* <---Default constructor---> initializes _fixedPointValue to 0 with member initializer list*/
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// int constructor
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

// float constructor
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

/* <---Copy constructor---> */
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // to force the copy assignment operator to be called fml
}

/* <---Destructor---> */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* <---Copy assignment constructor---> assigns one `Fixed` object to another*/
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other._fixedPointValue;
	}

	return *this;
}

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
