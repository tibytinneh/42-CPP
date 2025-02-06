#include "Fixed.hpp"
#include "Fixed.hpp"

void testEverything()
{
	std::cout << "================ TESTING COMPARISON OPERATORS ================\n";

	Fixed a(1.2f);
	Fixed b(4.3f);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "(a > b)  = " << (a > b) << std::endl;
	std::cout << "(a < b)  = " << (a < b) << std::endl;
	std::cout << "(a >= b) = " << (a >= b) << std::endl;
	std::cout << "(a <= b) = " << (a <= b) << std::endl;
	std::cout << "(a == b) = " << (a == b) << std::endl;
	std::cout << "(a != b) = " << (a != b) << std::endl;

	std::cout << "\n================ TESTING ARITHMETIC OPERATORS ================\n";

	Fixed c = a + b;
	Fixed d = a - b;
	Fixed e = a * b;
	Fixed f = a / b;

	std::cout << "a + b = " << c << std::endl;
	std::cout << "a - b = " << d << std::endl;
	std::cout << "a * b = " << e << std::endl;
	std::cout << "a / b = " << f << std::endl;

	std::cout << "\n================ TESTING INCREMENT/DECREMENT OPERATORS ================\n";

	Fixed g(2);
	std::cout << "Initial g = " << g << std::endl;

	std::cout << "++g = " << ++g << std::endl;
	std::cout << "g++ = " << g++ << std::endl;
	std::cout << "After g++ = " << g << std::endl;

	std::cout << "--g = " << --g << std::endl;
	std::cout << "g-- = " << g-- << std::endl;
	std::cout << "After g-- = " << g << std::endl;

	std::cout << "\n================ TESTING MIN/MAX FUNCTIONS ================\n";

	std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "Fixed::min(const a, const b) = " << Fixed::min(static_cast<const Fixed &>(a), static_cast<const Fixed &>(b)) << std::endl;
	std::cout << "Fixed::max(const a, const b) = " << Fixed::max(static_cast<const Fixed &>(a), static_cast<const Fixed &>(b)) << std::endl;
}

int main(void)
{

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	// std::cout << "\n.\n.\n.\n.\n.\n." << std::endl;
	// testEverything();
	return 0;
}
