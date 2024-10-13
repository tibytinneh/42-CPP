#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim("Jim", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    return 0;
}