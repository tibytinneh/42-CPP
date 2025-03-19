#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
   protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

   public:
    /* OCF */
    ClapTrap();                                  // default constructor
    ClapTrap(const std::string& name);           // string constructor
    ClapTrap(const ClapTrap& other);             // copy constructor
    ClapTrap& operator=(const ClapTrap& other);  // copy assignment constructor
    ~ClapTrap();                                 // destructor

    /* ACTIONS */
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void printAll() const;
    // /* GETTERS */
    std::string getName(void) const;
    int getAttackDamage(void) const;
    /* SETTERS */
    void setName(const std::string& name);
};

#endif