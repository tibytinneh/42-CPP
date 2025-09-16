#include "ScalarConverter.hpp"

// return: 1 = char literal, 0 = not char, 3 = char literal with quote
int ScalarConverter::isChar(const std::string &s) {
    // unquoted single
    if (s.size() == 1) {
        unsigned char c = static_cast<unsigned char>(s[0]);
        return !std::isdigit(c);
    } else if (s.size() == 3 && s[0] == '\'' && s[2] == '\'') {
        return 3;
    }
    return 0;
}
// return: 1 = float, 0 otherwise.
int ScalarConverter::isFloat(const std::string &s) {
    // pseudo
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return 1;
    // not float
    if (s.size() < 2 || s[s.size() - 1] != 'f')
        return 0;
    // remove f from body
    std::string body = s.substr(0, s.size() - 1);
    if (body.empty())
        return 0;
    std::size_t i = 0;
    // check for +/- sign
    if (body[0] == '+' || body[0] == '-')
        i++;
    bool hasDigit = false;
    bool hasDot = false;

    // for loop & return: to check for digits + 1 dot
    for (; i < body.size(); i++) {
        char c = body[i];
        if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigit = true;
        } else if (c == '.' && !hasDot) {
            hasDot = true;
        } else {
            return 0;  // gibberish
        }
    }
    std::cout << hasDigit << std::endl;
    std::cout << hasDot << std::endl;
    return (hasDigit && hasDot);
}

// return 1 if double, 0 otherwise.
int ScalarConverter::isDouble(const std::string &s) {
    // check pseudo
    if (s == "nan" || s == "+inf" || s == "-inf")
        return 1;
    // check size
    if (s.empty())
        return 0;
    std::size_t i = 0;

    if (s[0] == '+' || s[0] == '-') {
        i++;
    }
    bool hasDigit = false;
    bool hasDot = false;

    for (; i < s.size(); i++) {
        char c = s[i];
        if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigit = true;
        } else if (c == '.' && !hasDot) {
            hasDot = true;
        } else {
            return 0;  // gibberish
        }
    }
    return (hasDigit && hasDot);
}

int ScalarConverter::isInt(const std::string &s) {
    std::size_t i = 0;

    if (s[0] == '+' || s[0] == '-') {
        i++;
    }
    bool hasDigit = false;
    for (; i < s.size(); i++) {
        char c = s[i];
        if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigit = true;
        } else {
            return 0;  // gibberish
        }
    }
    return hasDigit;
}

void ScalarConverter::convert(std::string &s) {
    if (s.empty()) {
        std::cout << "String is empty." << std::endl;
        return;
    }

    char c = 69;
    int cchk = isChar(s);

    if (cchk == 1 || cchk == 3) {
        c = (s.size() == 1) ? s[0] : s[1];
        processChar(c);
        return;
    }
    if (cchk < 1) {
        if (isFloat(s))
            std::cout << s << " is a float" << std::endl;
        else if (isDouble(s))
            std::cout << s << " is a double" << std::endl;
        else if (isInt(s))
            std::cout << s << " is an int" << std::endl;
    }
}

void ScalarConverter::processChar(char c) {
    if (isprint(c))
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::setw(1) << std::fixed << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::processFloat(float f) {
    std::cout << "char: " << static_cast<char>(f) << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << static_cast<float>(f) << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}
void ScalarConverter::processDouble(double d) {
    std::cout << "char: " << static_cast<char>(d) << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << std::endl;
    std::cout << "double: " << static_cast<double>(d) << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &o) {
    (void)o;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &o) {
    (void)o;
    return *this;
}
ScalarConverter::~ScalarConverter() {}
