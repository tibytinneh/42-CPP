#include "Utils.hpp"

void announce(const std::string& color, const std::string& test) {
    std::cout << color << "Running test: " << test << RESET << std::endl;
}
