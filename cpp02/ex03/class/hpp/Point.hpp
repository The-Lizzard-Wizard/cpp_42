#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point &operator=(const Point &newF);
		Point(const Fixed pX, const Fixed pY);
		Point(const float pX, const float pY);
		Point(const Point &src);
		~Point();

		Fixed getX(void);
		Fixed getY(void);
	private:
		const Fixed x;
		const Fixed y;
};

#endif //POINT_HPP