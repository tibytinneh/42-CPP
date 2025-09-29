#include <iostream>
#include <cctype> //toupper
#include "iter.hpp"

void plus_one(int &i)
{
    i++;
}

void char_to_upper(char &c)
{
    c = std::toupper(c);
}
void to_upper(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
}

template <typename T>
void print_array(const T &element)
{
    std::cout << element << " ";
}

int main()
{
    std::cout << "testing int array, non-const" << std::endl;
    {
        int array_int[] = {1, 2, 3, 4, 5};
        std::size_t n = sizeof(array_int) / sizeof(array_int[0]);
        // ::iter(&array_int[0], n, print_array<int>); //explicit address
        ::iter(array_int, n, print_array<int>); // implicit conversion
        std::cout << std::endl;
    }
    {
        int array_int[] = {1, 2, 3, 4, 5};
        std::size_t n = sizeof(array_int) / sizeof(array_int[0]);
        ::iter(array_int, n, plus_one);
        ::iter(array_int, n, print_array<int>);
        std::cout << std::endl;
    }
    std::cout << "testing char array, non-const" << std::endl;
    {
        char array_char[] = "abcdef";
        std::size_t n = sizeof(array_char) / sizeof(array_char[0]);
        ::iter(array_char, n, print_array<char>);
        std::cout << std::endl;
    }
    {

        char array_char[] = "abcdef";
        std::size_t n = sizeof(array_char) / sizeof(array_char[0]);
        ::iter(array_char, n, char_to_upper);
        ::iter(array_char, n, print_array<char>);
        std::cout << std::endl;
    }
    std::cout << "testing string array, non-const" << std::endl;
    {
        std::string array_str[] = {"string 1", "string 2!!!", "string333!!"};
        std::size_t n = sizeof(array_str) / sizeof(array_str[0]);
        ::iter(array_str, n, print_array<std::string>);
        std::cout << std::endl;
    }
    {
        std::string array_str[] = {"string 1", "string 2!!!", "string333!!"};
        std::size_t n = sizeof(array_str) / sizeof(array_str[0]);
        ::iter(array_str, n, to_upper);
        ::iter(array_str, n, print_array<std::string>);
        std::cout << std::endl;
    }

    std::cout << "testing int array, const" << std::endl;
    {
        const int array_int[] = {1, 2, 3, 4, 5};
        std::size_t n = sizeof(array_int) / sizeof(array_int[0]);
        ::iter(&array_int[0], n, print_array<int>);
        std::cout << std::endl;
    }
    std::cout << "testing char array, const" << std::endl;
    {
        const char array_char[] = "abcdef";
        std::size_t n = sizeof(array_char) / sizeof(array_char[0]);
        ::iter(array_char, n, print_array<char>);
        std::cout << std::endl;
    }
    std::cout << "testing string array, const" << std::endl;
    {
        const std::string array_str[] = {"string 1", "string 2!!!", "string333!!"};
        std::size_t n = sizeof(array_str) / sizeof(array_str[0]);
        ::iter(array_str, n, print_array<std::string>);
        std::cout << std::endl;
    }
}