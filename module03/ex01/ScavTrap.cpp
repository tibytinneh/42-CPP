#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("") {
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    std::cout << "ScavTrap name is set to empty string." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap String constructor called" << std::endl;
    std::cout << "ScavTrap name is set to " << getName() << "." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap" << getName() << "destructor called" << std::endl;
}