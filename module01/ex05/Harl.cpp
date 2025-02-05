#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << C_BLUE "[ DEBUG ]\nI love having extra bacon for my "
						"7XL-double-cheese-triple-pickle-special-ketchup burger. "
						"I really do!\n"
			  << C_DEFAULT << std::endl;
}

void Harl::info(void)
{
	std::cout << C_YELLOW << "[ INFO ]\nI cannot believe adding extra bacon costs more money. "
							 "You didn’t put enough bacon in my burger! If you did, "
							 "I wouldn’t be asking for more!\n"
			  << C_DEFAULT << std::endl;
}

void Harl::warning(void)
{
	std::cout << C_RED << "[ WARNING ]\nI think I deserve to have some extra bacon for free. "
						  "I’ve been coming for years whereas you started working here "
						  "since last month.\n"
			  << C_DEFAULT << std::endl;
}

void Harl::error(void)
{
	std::cout << C_GREEN << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n"
			  << C_DEFAULT << std::endl;
}

void Harl::complain(void)
{
	Harl::complain("");
}
void Harl::complain(std::string level)
{
	// array of function pointers
	void (Harl::*functions[])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "No idea what the complaint level: \"" << level << "\" is.\n"
			  << std::endl;
}
