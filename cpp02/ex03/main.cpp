#include <iostream>
#include "class/hpp/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point p(5, 9.9);
	Point a(5, 0);
	Point b(0, 10);
	Point c(10, 10);
	if (bsp(a, b, c, p) == true)
		std::cout << "the point is in the triangle" << std::endl;
	else
		std::cout << "the point is out the triangle" << std::endl;
	return (0);
}