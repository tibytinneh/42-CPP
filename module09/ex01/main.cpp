/*  Your program must take an inverted Polish mathematical expression as an argument.
    *   The numbers used in this operation and passed as arguments will always be less
        than 10. The calculation itself but also the result do not take into account this rule.
    •   Your program must process this expression and output the correct result on the
        standard output.
    •   If an error occurs during the execution of the program an error message should be
        displayed on the standard error.
    • Your program must be able to handle operations with these tokens: "+ - / *".
*/

#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn;
    long long result = 0;
    if (!rpn.evaluate(av[1], result))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << result << std::endl;
    return 0;
}