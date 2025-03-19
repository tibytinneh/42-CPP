#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"),
                             ScavTrap(),
                             FragTrap() {
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
    std::cout << "DiamondTrap name is empty string." << std::endl;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::getDefaultEnergy();
    this->_attackDamage = FragTrap::_attackDamage;
    this->_gateStatus = 0;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"),
                                                    ScavTrap(),
                                                    FragTrap(),
                                                    _name(name) {
    std::cout << "DiamondTrap String constructor called" << std::endl;
    std::cout << "DiamondTrap name is set to " << this->_name << "." << std::endl;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = 50;
    this->_attackDamage = FragTrap::_attackDamage;
    this->_gateStatus = 0;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    this->_name = other._name;
    ClapTrap::_name = other.ClapTrap::_name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_gateStatus = other._gateStatus;
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    std::cout << "DiamondTrap " << this->_name << " has been copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap Copy assignment constructor called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        ClapTrap::_name = other.ClapTrap::_name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        this->_gateStatus = other._gateStatus;
        std::cout << "DiamondTrap " << this->_name << " has been assigned values." << std::endl;
    } else {
        std::cout << "Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }

    return *this;
};
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called!" << std::endl;
    if (this->_name == "")
        std::cout << "DiamondTrap has been destroyed." << std::endl;
    else
        std::cout << "DiamondTrap " << this->_name << " has been destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "\033[35m" << "WHO AM I? I AM.. " << this->_name << "... AKA " << ClapTrap::_name << "!" << "\033[0m" << std::endl;
}

void DiamondTrap::printAll() const {
    std::cout << "\t\t<-----" << std::endl;
    std::cout << "\t\tDiamondTrap Name: " << _name << std::endl;
    std::cout << "\t\tClapTrap Name: " << ClapTrap::_name << std::endl;
    std::cout << "\t\tHit Points: " << _hitPoints << std::endl;
    std::cout << "\t\tEnergy Points: " << _energyPoints << std::endl;
    std::cout << "\t\tAttack Damage: " << _attackDamage << std::endl;
    std::cout << "\t\t----->" << std::endl;
}
