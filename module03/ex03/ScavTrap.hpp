#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
   protected:
    unsigned int _gateStatus;

   public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);             // copy constructor
    ScavTrap& operator=(const ScavTrap& other);  // copy assignment constructor
    ~ScavTrap();

    void guardGate();
    unsigned int getGateStatus() const;
    void setGateStatus(unsigned int status);
    void printGateStatus() const;
    void printAll() const;
    void attack(const std::string& target);

    int getDefaultEnergy() const;
    int _defaultEnergy;
};

#endif