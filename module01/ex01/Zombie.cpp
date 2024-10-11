#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::Zombie(std::string name): _Name(name){}
Zombie::~Zombie(){cout << _Name << ": has destructed" << endl;}

// announces themsleves as follows: <name>: BraiiiiiiinnnzzzZ...
void Zombie::announce( void ){
	cout << _Name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void Zombie::setName(std::string name)
{
    _Name = name;
}