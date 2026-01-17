#include "../hpp/Fixed.hpp"
#include <iostream>


Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixedPoint = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called\n";
	fixedPoint = src.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &newF)
{
	std::cout << "Copy assignment operator called\n";

	if (this == &newF)
		return (*this);
	this->setRawBits(newF.getRawBits());
	return (*this);
}

Fixed::~Fixed(){ std::cout << "Destructor called\n"; }

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	fixedPoint = raw;
}
