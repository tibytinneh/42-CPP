#include "Point.hpp"
#include "Fixed.hpp"

/** Barycentric coordinate system
 * Determines if a point is inside a triangle
 * * Calculates the total area of the triangle and compares it to the sum
 * of three sub-triangle areas formed with the point.
 * If the areas match and none are zero, the point is inside.
 **/

static Fixed calculateArea(Point const a, Point const b, Point const c)
{
	Fixed temp =
		((a.getX() * (b.getY() - c.getY()) +
		  b.getX() * (c.getY() - a.getY()) +
		  c.getX() * (a.getY() - b.getY())) /
		 2.0f);
	if (temp < 0)
		return temp * -1;
	return temp;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = calculateArea(a, b, c);
	Fixed areaABP = calculateArea(a, b, point);
	Fixed areaBCP = calculateArea(b, c, point);
	Fixed areaCAP = calculateArea(c, a, point);

	return (areaABC == (areaABP + areaBCP + areaCAP));
}
