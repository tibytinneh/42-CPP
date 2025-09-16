#pragma once
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

class ScalarConverter {
   public:
    static void convert(std::string &exp);

   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &o);
    ScalarConverter &operator=(const ScalarConverter &o);
    ~ScalarConverter();
    static int isChar(const std::string &s);
    static int isFloat(const std::string &s);
    static int isDouble(const std::string &s);
    static int isInt(const std::string &s);
    static void processChar(char c);
    static void processFloat(float f);
    static void processDouble(double d);
    static void processInt(int i);
};
