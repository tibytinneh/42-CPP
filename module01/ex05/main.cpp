#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac != 2)
	{
		std::cout << "Aite I'm about to complain\n.\n.\n.\n.\n"
				  << std::endl;

		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");

		std::cout << "Aite I'm about to complain random shit\n.\n.\n.\n.\n"
				  << std::endl;

		harl.complain("23232");
		harl.complain();
		harl.complain("BULLSHIT");
		harl.complain("UWU");

		return (0);
	}
	harl.complain(av[1]);
	return (0);
}
