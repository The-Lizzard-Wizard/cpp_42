#include "../hpp/Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed pX, const Fixed pY) : x(pX), y(pY) {}

Point::Point(const float pX, const float pY) : x(pX), y(pY) {};

Point::Point(const Point &src) : x(src.x), y(src.y) {}

Point &Point::operator=(const Point &newF)
{
	(void)newF;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX(void)
{
	return (x);
}

Fixed Point::getY(void)
{
	return (y);
}
