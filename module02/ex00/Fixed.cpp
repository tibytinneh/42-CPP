#include "Fixed.hpp"

/**	<<---OCF-->>
**	Default constructor -> inits objects with no args are provided
**	Copy constructor -> creates a new object as a copy of an existing one
**	Copy assignment constructor -> allow one object to be assigned the value of another
**	Destructor -> cleans up resources when object goes out of scope
**/

/* <---Default constructor---> initializes _fixedPointValue to 0 with member initializer list*/
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* <---Copy constructor---> creates a new object as copy of existing one*/
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = other.getRawBits();
}

/* <---Copy assignment constructor---> assigns one `Fixed` object to another*/
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}

	return *this;
}

/* <---Destructor---> */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member cuntion called" << std::endl;
	this->_fixedPointValue = raw;
}
