#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
   public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);             // copy constructor
    FragTrap& operator=(const FragTrap& other);  // copy assignment constructor
    ~FragTrap();

    void highFivesGuys(void);
    void attack(const std::string& target);
};

#endif