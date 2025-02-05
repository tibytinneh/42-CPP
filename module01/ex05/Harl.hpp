#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define C_RED "\033[31m"
#define C_BLUE "\033[34m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_DEFAULT "\033[0m"

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl();
	~Harl();
	void complain(void);
	void complain(std::string level);
};

#endif // HARL_HPP
