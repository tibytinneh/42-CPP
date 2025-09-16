
#include <string.h>

#include <cctype>
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"
void process_char(char* av) {
    std::cout << "char: " << static_cast<char>(*av) << std::endl;
    std::cout << "int: " << static_cast<int>(*av) << std::endl;
    std::cout << "float: " << static_cast<float>(*av) << std::endl;
    std::cout << "double: " << static_cast<double>(*av) << std::endl;
}

int main(int ac, char* av[]) {
    // invalid number of arguments
    if (ac != 2) {
        (void)av;
        std::cout << "Invalid number of arguments: " << ac << std::endl;
        return 0;
    }

    std::string s = av[1];
    ScalarConverter::convert(s);

    return 1;
}