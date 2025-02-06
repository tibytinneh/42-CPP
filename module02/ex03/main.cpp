#include "Point.hpp"
#include <iostream>

extern bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point a, Point b, Point c, Point p)
{
	std::cout << "Point P is "
			  << (bsp(a, b, c, p) ? "inside" : "outside")
			  << " the triangle." << std::endl;
}

int main()
{
	Point a(0, 0), b(10, 0), c(5, 10);
	test(a, b, c, Point(-5, -5));
	test(a, b, c, Point(0, 0));
	test(a, b, c, Point(3, 3));
	test(a, b, c, Point(10, 0));
	test(a, b, c, Point(10, 10));

	std::cout << "\n.\n.\n.\n." << std::endl;
	Point e(0, 0), f(-10, 0), g(5, 10);
	test(e, f, g, Point(-5, -5));
	test(e, f, g, Point(0, 0));
	test(e, f, g, Point(3, 3));
	test(e, f, g, Point(10, 0));
	test(e, f, g, Point(10, 10));

	return 0;
}
