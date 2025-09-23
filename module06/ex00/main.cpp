
#include <string.h>

#include <cctype>
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    // invalid number of arguments
    if (ac != 2)
    {
        (void)av;
        std::cout << "Invalid number of arguments: " << ac << std::endl;
        return 0;
    }

    std::string s = av[1];
    ScalarConverter::convert(s);

    return 1;
}