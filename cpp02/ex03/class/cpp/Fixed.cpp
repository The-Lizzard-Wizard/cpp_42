#include "../hpp/Fixed.hpp"
#include <iostream>
#include <cmath>
//#include <bool.h>

//constructor and destructor

Fixed::Fixed()
{
	fixedPoint = 0;
}

Fixed::Fixed(const int Fp)
{
	fixedPoint = Fp << size;
}

Fixed::Fixed(const float Fp)
{
	fixedPoint = roundf(Fp * (1 << size));
}

Fixed::Fixed(const Fixed &src)
{
	fixedPoint = src.getRawBits();
}

Fixed::~Fixed(){}

//operator

Fixed &Fixed::operator=(const Fixed &newF)
{
	if (this == &newF)
		return (*this);
	this->setRawBits(newF.getRawBits());
	return (*this);
}

Fixed Fixed::operator+(const Fixed &b)
{
	return (Fixed(this->toFloat() + b.toFloat()));
}

Fixed Fixed::operator-(const Fixed &b)
{
	return (Fixed(this->toFloat() - b.toFloat()));
}

Fixed &Fixed::operator++()
{
	this->fixedPoint++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->fixedPoint--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixedPoint++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedPoint--;
	return (tmp);
}


Fixed Fixed::operator/(const Fixed &b)
{
	return (Fixed(this->toFloat() / b.toFloat()));
}

Fixed Fixed::operator*(const Fixed &b)
{
	return (Fixed(this->toFloat() * b.toFloat()));
}

bool Fixed::operator>(const Fixed &b) const
{
	if (this->getRawBits() > b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &b) const
{
	if (this->getRawBits() < b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &b) const
{
	if (this->getRawBits() >= b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &b) const
{
	if (this->getRawBits() <= b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &b) const
{
	if (this->getRawBits() == b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &b) const
{
	if (this->getRawBits() != b.getRawBits())
		return (true);
	return (false);
}

std::ostream& operator<<(std::ostream& stream, const Fixed &fix)
{
	stream << fix.toFloat();
	return (stream);
}

//mumbers functions

int Fixed::getRawBits( void ) const
{
	return (fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
	float ret;
	ret = (float)fixedPoint / (float)(1 << size);
	return (ret);
}

int Fixed::toInt( void ) const
{
	int ret;
	ret = fixedPoint >> size;
	return (ret);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
