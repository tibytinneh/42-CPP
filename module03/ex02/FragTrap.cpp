#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("") {
    std::cout << "FragTrap Default Constructor called" << std::endl;
    std::cout << "FragTrap name is empty string." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap String constructor called" << std::endl;
    std::cout << "FragTrap name is set to " << this->_name << "." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "FragTrap Copy constructor called" << std::endl;
    std::cout << "FragTrap " << this->_name << " has been copied." << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap Copy assignment constructor called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        std::cout << "FragTrap " << this->_name << " has been assigned values." << std::endl;
    } else {
        std::cout << "Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }

    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called!" << std::endl;
    if (this->_name == "")
        std::cout << "FragTrap has been destroyed." << std::endl;

    else
        std::cout << "FragTrap " << this->_name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "\033[33m" << "VERY POSITIVE HIGH FIVE?!?! TO " << this->_name << "\033[0m" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " cannot attack; energy or hit points are insufficient." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
};