
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
public:

// announces themsleves as follows: <name>: BraiiiiiiinnnzzzZ...
void announce( void );

// creates a zombie, name it, returns it to use outside of function scope.
Zombie* newZombie( std::string name);

// creates a zombie, name it, and the zombie announces itself. 
void randomChump( std::string name);

/*
zombies must be destroyed when we don't need them anymore.
the destructor must print a message with the name of the zombie for debugging purposes.
*/


private:


};

#endif // ZOMBIE_HPP