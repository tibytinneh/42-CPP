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

void announce(const std::string& test) {
    std::cout << CYAN << test << RESET << std::endl;
}

void announceStartLine() {
    std::cout << CYAN << "------------ [START] ------------" << RESET << std::endl;
}

void announceEndLine() {
    std::cout << CYAN << "------------[END]------------" << RESET << std::endl;
}

void announceLine() {
    std::cout << CYAN << "------------------------" << RESET << std::endl;
}