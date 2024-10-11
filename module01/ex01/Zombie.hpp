
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;

#define C_RED     "\033[31m"
#define C_BLUE    "\033[34m"
#define C_GREEN   "\033[32m"
#define C_YELLOW  "\033[33m"
#define C_DEFAULT "\033[0m"

class Zombie{
public:
Zombie(); //default constructor
Zombie(std::string name); //parameterized constructor
~Zombie();

void 	announce( void );
void	setName(std::string name);


private:
std::string _Name;
};

#endif // ZOMBIE_HPP