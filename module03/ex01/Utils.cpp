#include "Utils.hpp"

void announceBlue(const std::string& test) {
    std::cout << BLUE << "Running test: " << test << RESET << std::endl;
}
void announceRed(const std::string& test) {
    std::cout << RED << "Running test: " << test << RESET << std::endl;
}
void announceGreen(const std::string& test) {
    std::cout << GREEN << "Running test: " << test << RESET << std::endl;
}