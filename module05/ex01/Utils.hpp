#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

// ANSI escape codes for colors
#define RESET "\033[0m"     // Reset to default color
#define DEFAULT "\033[0m"   // Reset to default color
#define RED "\033[31m"      // Red
#define GREEN "\033[32m"    // Green
#define YELLOW "\033[33m"   // Yellow
#define BLUE "\033[34m"     // Blue
#define MAGENTA "\033[35m"  // Magenta
#define CYAN "\033[36m"     // Cyan

void announce(const std::string& color, const std::string& test);

#endif  // UTILS_HPP
