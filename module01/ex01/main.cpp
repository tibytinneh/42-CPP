
#include "Zombie.hpp"

Zombie* newZombie( std::string name);
void randomChump( std::string name);
Zombie* zombieHorde(int N, std::string name );

int main()
{
cout << "----------------------------------------------------------------" << endl;
cout << "----------------------------------------------------------------" << endl;
	cout << C_GREEN << "Zombie* zombieHorde5 = zombieHorde(5, \"Zombie Horder member\")"	<< C_DEFAULT << endl;
	cout << C_RED << "zombieHorde5 is a dynamic heap-allocated object" << C_DEFAULT << endl;
	Zombie* zombieHorde5 = zombieHorde(5, "Zombie Horde member");
	cout << "----------------------------------------------------------------" << endl;
	cout << C_GREEN << "delete[] zombieHorde5;" << C_DEFAULT << endl;
	cout << C_RED << "zombieHorde5 is manually deleted" << C_DEFAULT << endl;
	delete[] zombieHorde5;
	cout << "----------------------------------------------------------------" << endl;
	
	return 0;
}