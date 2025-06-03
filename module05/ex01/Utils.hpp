#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

// ANSI escape codes for colors
#define RESET "\033[0m"     // Reset to default color
#define RED "\033[31m"      // Red
#define GREEN "\033[32m"    // Green
#define YELLOW "\033[33m"   // Yellow
#define BLUE "\033[34m"     // Blue
#define MAGENTA "\033[35m"  // Magenta
#define CYAN "\033[36m"     // Cyan

void announceBlue(const std::string& test);
void announceRed(const std::string& test);
void announceGreen(const std::string& test);
void announce(const std::string& test);
void announceStartLine();
void announceEndLine();
void announceLine();

#endif  // UTILS_HPP
