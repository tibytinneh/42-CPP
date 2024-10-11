#include "Zombie.hpp"

// creates a zombie, name it, returns it to use outside of function scope.
Zombie* newZombie( std::string name)
{
    Zombie* zombie1_heap = new Zombie(name); // `new` allocates memory on the heap
	return zombie1_heap;
};

// as a dynamic heap-allocated object
// zombie1 persists beyond the function scope
// the caller must manually delete the object to prevent memory leaks