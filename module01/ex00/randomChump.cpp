#include "Zombie.hpp"

// creates a zombie, name it, and the zombie announces itself. 
void randomChump( std::string name ){
	Zombie zombie2_stack( name ); // automatically allocates memory on the stack
	zombie2_stack.announce();
}

// as a local stack-allocated object
// zombie2 limited to function scope
// zombie2 is automatically destroyed when randomChump exits