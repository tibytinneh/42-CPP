#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(""), _gateStatus(0) {
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    std::cout << "ScavTrap name is empty string." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _gateStatus(0) {
    std::cout << "ScavTrap String constructor called" << std::endl;
    std::cout << "ScavTrap name is set to " << getName() << "." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}
ScavTrap::ScavTrap(const ScavTrap& other) {
    setName(other.getName());
    setHitPoints(other.getHitPoints());
    setEnergyPoints(other.getEnergyPoints());
    setAttackDamage(other.getAttackDamage());
    setGateStatus(other.getGateStatus());
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    std::cout << "ScavTrap " << getName() << " has been copied." << std::endl;
};
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap Copy assignment constructor called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << getName() << " has been assigned values." << std::endl;
    } else {
        std::cout << "Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }

    return *this;
};

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called!" << std::endl;
    if (getName() == "")
        std::cout << "ScavTrap has been destroyed." << std::endl;

    else
        std::cout << "ScavTrap " << getName() << " has been destroyed." << std::endl;
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
