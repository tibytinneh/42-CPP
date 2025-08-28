#include "Utils.hpp"

void announceBlue(const std::string &test)
{
    std::cout << BLUE << test << RESET << std::endl;
}
void announceRed(const std::string &test)
{
    std::cout << RED << test << RESET << std::endl;
}
void announceGreen(const std::string &test)
{
    std::cout << GREEN << test << RESET << std::endl;
}

void announce(const std::string &test)
{
    std::cout << CYAN << test << RESET << std::endl;
}

void announceStartLine()
{
    std::cout << CYAN << "------------ [START] ------------" << RESET << std::endl;
}

void announceEndLine()
{
    std::cout << CYAN << "------------[END]------------" << RESET << std::endl;
}

void announceLine()
{
    std::cout << CYAN << "------------------------" << RESET << std::endl;
}

void announceStart()
{
    std::cout << CYAN << "    ________  _________  ________  ________  _________   \n"
                         "|\\   ____\\|\\___   ___\\\\   __  \\|\\   __  \\|\\___   ___\\ \n"
                         "\\ \\  \\___|\\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\|\\  \\|___ \\  \\_| \n"
                         " \\ \\_____  \\   \\ \\  \\ \\ \\   __  \\ \\   _  _\\   \\ \\  \\  \n"
                         "  \\|____|\\  \\   \\ \\  \\ \\ \\  \\ \\  \\ \\  \\\\  \\|   \\ \\  \\ \n"
                         "    ____\\_\\  \\   \\ \\__\\ \\ \\__\\ \\__\\ \\__\\\\ _\\    \\ \\__\\\n"
                         "   |\\_________\\   \\|__|  \\|__|\\|__|\\|__|\\|__|    \\|__|\n"
                         "   \\|_________|                                       "
              << RESET << std::endl;
}

void announceEnd()
{
    std::cout << CYAN << " _______   ________   ________     \n"
                         "|\\  ___ \\ |\\   ___  \\|\\   ___ \\    \n"
                         "\\ \\   __/|\\ \\  \\\\ \\  \\ \\  \\_|\\ \\   \n"
                         " \\ \\  \\_|/_\\ \\  \\\\ \\  \\ \\  \\ \\\\ \\  \n"
                         "  \\ \\  \\_|\\ \\ \\  \\\\ \\  \\ \\  \\_\\\\ \\ \n"
                         "   \\ \\_______\\ \\__\\\\ \\__\\ \\_______\\\n"
                         "    \\|_______|\\|__| \\|__|\\|_______|"
              << RESET << std::endl;
}