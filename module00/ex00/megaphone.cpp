#include <iostream> // for input and output
#include <cctype> // for std::toupper()

/**
 * @brief converts string to uppercase.
 * 
 * static_cast<char> explicitly converts the int returned by std::toupper back into a char
 *
 * similar to C's  (char) conversion.
 * @param str string to convert.
 */
void strToUpperCase(char* str)
{
    for(std::size_t i = 0; str[i] != '\0'; i++){
        str[i] = static_cast<char>(std::toupper(str[i]));
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        int i = 1;
        while (i < argc) {
            strToUpperCase(argv[i]);
            std::cout << argv[i];
            ++i;
        }
        std::cout << std::endl;
    }
}
