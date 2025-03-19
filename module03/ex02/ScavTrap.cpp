#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(""), _gateStatus(0) {
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    std::cout << "ScavTrap name is empty string." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _gateStatus(0) {
    std::cout << "ScavTrap String constructor called" << std::endl;
    std::cout << "ScavTrap name is set to " << this->_name << "." << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_gateStatus = other._gateStatus;

    std::cout << "ScavTrap Copy constructor called" << std::endl;
    std::cout << "ScavTrap " << this->_name << " has been copied." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap Copy assignment constructor called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        this->_gateStatus = other._gateStatus;
    }
    if (this->_name == "")
        std::cout << "ScavTrap " << this->_name << " has been assigned values." << std::endl;
    else {
        std::cout << "Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called!" << std::endl;
    if (this->_name == "")
        std::cout << "ScavTrap has been destroyed." << std::endl;

    else
        std::cout << "ScavTrap " << this->_name << " has been destroyed." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "Gate status: ";
    if (!getGateStatus()) {
        std::cout << "SWITCH TO GUARDED." << std::endl;
        setGateStatus(1);
    } else {
        std::cout << "SWITCH TO UNGUARDED." << std::endl;
        setGateStatus(0);
    }
}
unsigned int ScavTrap::getGateStatus() const {
    return _gateStatus;
}

void ScavTrap::setGateStatus(unsigned int status) {
    _gateStatus = status;
}

void ScavTrap::printGateStatus() const {
    if (!getGateStatus()) {
        std::cout << "UNGUARDED" << std::endl;
    } else {
        std::cout << "GUARDED" << std::endl;
    }
}
void ScavTrap::printAll() const {
    ClapTrap::printAll();
    std::cout << "\t\t Guard Status: ";
    printGateStatus();
}
void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " cannot attack; energy or hit points are insufficient." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
};