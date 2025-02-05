
#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	cout << C_GREEN << "newZombie(\"Zombie 1\")" << C_DEFAULT << endl;
	cout << C_BLUE << "creates a zombie, name it, returns it to use outside of function scope " << C_DEFAULT << endl;
	Zombie *zombie1 = newZombie("Zombie 1");
	cout << "----------------------------------------------------------------" << endl;
	cout << C_GREEN << "zombie1->announce()" << C_DEFAULT << endl;
	cout << C_BLUE << "Announces themselves as follows: _Name : BraiiiiiiinnnzzzZ..." << C_DEFAULT << endl;
	zombie1->announce();
	cout << "----------------------------------------------------------------" << endl;
	cout << C_GREEN << "randomChump(\"Zombie 2\")" << C_DEFAULT << endl;
	cout << C_BLUE << "creates a zombie, name it, and the zombie announces itself." << C_DEFAULT << endl;
	cout << C_RED << "zombie2 is an automatic stack-allocated object" << C_DEFAULT << endl;
	cout << C_RED << "zombie2 is limited to function scope" << C_DEFAULT << endl;
	cout << C_RED << "zombie2 is automatically destroyed when randomChump() exits" << C_DEFAULT << endl;
	randomChump("Zombie 2");
	cout << "----------------------------------------------------------------" << endl;
	cout << C_GREEN << "delete zombie1;" << C_DEFAULT << endl;
	cout << C_RED << "zombie1 is a dynamic heap-allocated object" << C_DEFAULT << endl;
	cout << C_RED << "zombie1 persists beyond the function scope" << C_DEFAULT << endl;
	cout << C_RED << "zombie1 must be manually deleted to prevent memleak" << C_DEFAULT << endl;
	delete zombie1; // destroy the zombie when we're done with it.
	cout << "----------------------------------------------------------------" << endl;
	return 0;
}
