#include "ClapTrap.hpp"

/* OCF */

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Constructor called" << std::endl;
    std::cout << "ClapTrap name is set to empty string." << std::endl;
};
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap String constructor called" << std::endl;
    if (this->_name == "")
        std::cout << "ClapTrap name is empty string." << std::endl;
    else
        std::cout << "ClapTrap name is set to " << name << "." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    std::cout << "ClapTrap " << other._name << " has been copied." << std::endl;
};
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap Copy assignment constructor called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;

        std::cout << "ClapTrap " << _name << " has been assigned values." << std::endl;
    } else {
        std::cout << "Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }

    return *this;
};
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called!" << std::endl;
    if (this->_name == "")
        std::cout << "ClapTrap has been destroyed." << std::endl;

    else
        std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
};

/* ACTIONS */
void ClapTrap::attack(const std::string& target) {
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot attack; energy or hit points are insufficient." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
};

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "Cannot be attacked, ClapTrap " << _name << " has zero hit points." << std::endl;
        return;
    }
    if (amount >= static_cast<unsigned int>(_hitPoints)) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " took damage, and now has zero hit points." << std::endl;
    } else if (amount == 0) {
        std::cout << "ClapTrap " << _name << " did not receive any damage, and now has " << _hitPoints << " hitpoints." << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " took " << amount << " damage, and now has " << _hitPoints << " hitpoints." << std::endl;
    }
};

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot repair itself; energy or hit points are insufficient." << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " has repaired itself by " << amount << " hit points." << std::endl;
};

void ClapTrap::printAll() const {
    std::cout
        << "\t\t<-----" << std::endl
        << "\t\tName: " << _name << std::endl;
    std::cout << "\t\tHit Points: " << _hitPoints << std::endl;
    std::cout << "\t\tEnergy Points: " << _energyPoints << std::endl;
    std::cout << "\t\tAttack Damage: " << _attackDamage << std::endl
              << "\t\t----->" << std::endl;
}

// /* GETTERS */
std::string ClapTrap::getName(void) const { return this->_name; };
int ClapTrap::getAttackDamage(void) const { return _attackDamage; };

// /* SETTERS */
void ClapTrap::setName(const std::string& name) {
    _name = name;
}
