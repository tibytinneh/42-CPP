
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

/*
zombies must be destroyed when we don't need them anymore.
the destructor must print a message with the name of the zombie for debugging purposes.
*/
class Zombie{
public:
Zombie(std::string name);
~Zombie();

// announces themsleves as follows: <name>: BraiiiiiiinnnzzzZ...
void announce( void );


private:
std::string _Name;
};

#endif // ZOMBIE_HPP