#include "../include/Point.hpp"

static Fixed crossProduct(Point const& v1, Point const& v2, Point const& p) {
	return (v2.getX() - v1.getX()) * (p.getY() - v1.getY())
		- (v2.getY() - v1.getY()) * (p.getX() - v1.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed crossAB = crossProduct(a, b, point);
	Fixed crossBC = crossProduct(b, c, point);
	Fixed crossCA = crossProduct(c, a, point);

	if (crossAB == 0 || crossBC == 0 || crossCA == 0)
		return false;

	return ((crossAB > 0) && (crossBC > 0) && (crossCA > 0))
		|| ((crossAB < 0) && (crossBC < 0) && (crossCA < 0));
}
