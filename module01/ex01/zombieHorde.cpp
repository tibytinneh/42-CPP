#include "Zombie.hpp"

Zombie* newZombie( std::string name);

/**
 * @brief creates a horde of Zombies
 * Allocate N Zombie objects ion a single allocation
 * Initializes the zombies, giving each of them the name passed as a parameter
 * returns a pointer to the first zombie
 */
Zombie* zombieHorde(int N, std::string name ){
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++){
		horde[i].setName(name); 
		horde[i].announce();
    }
	return horde;
}