
#include <iostream>
#include "Whatever.hpp"

//** 42 */
// int main( void ) {
// int a = 2;
// int b = 3;
// ::swap( a, b );
// std::cout << "a = " << a << ", b = " << b << std::endl;
// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// std::string c = "chaine1";
// std::string d = "chaine2";
// ::swap(c, d);
// std::cout << "c = " << c << ", d = " << d << std::endl;
// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// return 0;
// }

int main()
{
    //** void swap(T &a, T &b) */
    {
        int a = 333;
        int b = 444;

        std::cout << "swap test: int" << std::endl;
        std::cout << "a: " << a << std::endl
                  << "b: " << b << std::endl
                  << std::endl;
        ::swap(a, b);

        std::cout << "a : " << a << std::endl
                  << "b: " << b << std::endl
                  << std::endl;
    }
    {
        char a = 'a';
        char b = 'b';

        std::cout << "swap test: char" << std::endl;
        std::cout << "a: " << a << std::endl
                  << "b:" << b << std::endl
                  << std::endl;
        ::swap(a, b);

        std::cout << "a: " << a << std::endl
                  << "b:" << b << std::endl
                  << std::endl;
    }
    {
        std::string a = "apple";
        std::string b = "banana";

        std::cout << "swap test: string" << std::endl;
        std::cout << "a: " << a << std::endl
                  << "b:" << b << std::endl
                  << std::endl;
        ::swap(a, b);

        std::cout << "a: " << a << std::endl
                  << "b:" << b << std::endl
                  << std::endl;
    }

    //** T const &min(T const &a, T const &b) */
    //** T const &max(T const &a, T const &b) */
    {
        int a = 333;
        int b = 444;

        std::cout << "min max test: int" << std::endl;
        std::cout << "a: " << a << std::endl
                  << "b: " << b << std::endl
                  << std::endl;
        std::cout << "min: " << ::min(a, b) << std::endl;
        std::cout << "max: " << ::max(a, b) << std::endl
                  << std::endl;
    }
    {
        char a = 'a';
        char b = 'b';

        std::cout << "min max test: char" << std::endl;
        std::cout << "a: " << a << std::endl
                  << "b: " << b << std::endl
                  << std::endl;
        std::cout << "min: " << ::min(a, b) << std::endl;
        std::cout << "max: " << ::max(a, b) << std::endl
                  << std::endl;
    }
    {

        std::string a = "apple";
        std::string b = "banana";

        std::cout << "min max test: int" << std::endl;
        std::cout << "a: " << a << std::endl
                  << "b: " << b << std::endl
                  << std::endl;
        std::cout << "min: " << ::min(a, b) << std::endl;
        std::cout << "max: " << ::max(a, b) << std::endl
                  << std::endl;
    }
}