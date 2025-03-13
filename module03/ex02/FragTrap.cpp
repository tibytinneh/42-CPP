#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("") {
    std::cout << "FragTrap Default Constructor called" << std::endl;
    std::cout << "FragTrap name is empty string." << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap String constructor called" << std::endl;
    std::cout << "FragTrap name is set to " << getName() << "." << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}
FragTrap::FragTrap(const FragTrap& other) {
    setName(other.getName());
    setHitPoints(other.getHitPoints());
    setEnergyPoints(other.getEnergyPoints());
    setAttackDamage(other.getAttackDamage());
    std::cout << "FragTrap Copy constructor called" << std::endl;
    std::cout << "FragTrap " << getName() << " has been copied." << std::endl;
};
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap Copy assignment constructor called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << getName() << " has been assigned values." << std::endl;
    } else {
        std::cout << "Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }

    return *this;
};

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called!" << std::endl;
    if (getName() == "")
        std::cout << "FragTrap has been destroyed." << std::endl;

    else
        std::cout << "FragTrap " << getName() << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "\033[33m" << "VERY POSITIVE HIGH FIVE?!?! TO " << getName() << "\033[0m" << std::endl;
}