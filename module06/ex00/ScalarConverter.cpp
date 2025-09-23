#include "ScalarConverter.hpp"

// return: 1 = char literal, 0 = not char, 3 = char literal with quote
int ScalarConverter::isChar(const std::string &s)
{
    // unquoted single
    if (s.size() == 1)
    {
        unsigned char c = static_cast<unsigned char>(s[0]);
        return !std::isdigit(c);
    }
    else if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
    {
        return 3;
    }
    return 0;
}
// return: 1 = float, 0 otherwise.
int ScalarConverter::isFloat(const std::string &s)
{
    // pseudo
    if (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
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
    for (; i < body.size(); i++)
    {
        char c = body[i];
        if (std::isdigit(static_cast<unsigned char>(c)))
        {
            hasDigit = true;
        }
        else if (c == '.' && !hasDot)
        {
            hasDot = true;
        }
        else
        {
            return 0; // gibberish
        }
    }
    return (hasDigit && hasDot);
}

// return 1 if double, 0 otherwise.
int ScalarConverter::isDouble(const std::string &s)
{
    // check pseudo
    if (s == "nan" || s == "+inf" || s == "-inf" || s == "inf")
        return 1;
    // check size
    if (s.empty())
        return 0;
    std::size_t i = 0;

    if (s[0] == '+' || s[0] == '-')
    {
        i++;
    }
    bool hasDigit = false;
    bool hasDot = false;

    for (; i < s.size(); i++)
    {
        char c = s[i];
        if (std::isdigit(static_cast<unsigned char>(c)))
        {
            hasDigit = true;
        }
        else if (c == '.' && !hasDot)
        {
            hasDot = true;
        }
        else
        {
            return 0; // gibberish
        }
    }
    return (hasDigit && hasDot);
}

int ScalarConverter::isInt(const std::string &s)
{
    std::size_t i = 0;

    if (s[0] == '+' || s[0] == '-')
    {
        i++;
    }
    bool hasDigit = false;
    for (; i < s.size(); i++)
    {
        char c = s[i];
        if (std::isdigit(static_cast<unsigned char>(c)))
        {
            hasDigit = true;
        }
        else
        {
            return 0; // gibberish
        }
    }
    return hasDigit;
}

void ScalarConverter::convert(std::string &s)
{
    if (s.empty())
    {
        std::cout << "String is empty." << std::endl;
        return;
    }

    int cchk = isChar(s);

    if (cchk == 1 || cchk == 3)
    {
        char c = (s.size() == 1) ? s[0] : s[1];
        processChar(c);
        return;
    }
    if (cchk < 1)
    {
        if (isFloat(s))
        {
            float f;
            if (s == "nanf")
                f = std::numeric_limits<float>::quiet_NaN();
            else if (s == "+inff" || s == "inff")
                f = std::numeric_limits<float>::infinity();
            else if (s == "-inff")
                f = -std::numeric_limits<float>::infinity();
            else
                f = std::atof(s.c_str());
            processFloat(f);
        }
        else if (isDouble(s))
        {
            double d;
            if (s == "nan")
                d = std::numeric_limits<double>::quiet_NaN();
            else if (s == "+inf" || s == "inf")
                d = std::numeric_limits<double>::infinity();
            else if (s == "-inf")
                d = -std::numeric_limits<double>::infinity();
            else
                d = std::atof(s.c_str());
            processDouble(d);
        }
        else if (isInt(s))
        {
            // Check for int overflow/underflow before conversion
            double temp = std::atof(s.c_str());
            if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(temp) << "f" << std::endl;
                std::cout << "double: " << std::fixed << std::setprecision(1) << temp << std::endl;
            }
            else
            {
                int i = std::atoi(s.c_str());
                processInt(i);
            }
        }
    }
}

void ScalarConverter::processChar(char c)
{
    // check: if char is printable
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::processFloat(float f)
{
    // check: Handle special float values for char and int (-inff, +inff, inff, nanf)
    if (std::isnan(f) || std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        // check: if float is within valid char range (0-255 for unsigned char)
        if (f < 0 || f > 255)
            std::cout << "char: impossible" << std::endl;
        else if (isprint(static_cast<char>(f)))
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        // check: if float is within valid int range
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}
void ScalarConverter::processDouble(double d)
{
    // check: Handle special double values for char and int (-inf, +inf, inf, nan)
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        // check: if double is within valid char range (0-255 for unsigned char)
        if (d < 0 || d > 255)
            std::cout << "char: impossible" << std::endl;
        else if (isprint(static_cast<char>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        // check: if double is within valid int range
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
    }

    // check: if double is within valid float range
    if (std::isnan(d) || std::isinf(d))
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    else if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::processInt(int i)
{
    // Check: if int is within valid char range (0-255 for unsigned char)
    if (i < 0 || i > 255)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(i)))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &o)
{
    (void)o;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &o)
{
    (void)o;
    return *this;
}
ScalarConverter::~ScalarConverter() {}
