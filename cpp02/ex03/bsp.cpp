#include "class/hpp/Point.hpp"

Fixed sign(Point p, Point a, Point b)
{
	return ((p.getX() - b.getX()) * (a.getY() - b.getY())
	 - (p.getY() - b.getY()) * (a.getX() - b.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed pab = sign(point, a, b);
	Fixed pbc = sign(point, b, c);
	Fixed pca = sign(point, c, a);

	if ((pab < 0) && (pbc < 0) && (pca < 0))
		return (true);
	if ((pab > 0) && (pbc > 0) && (pca > 0))
		return (true);
	return (false);
}