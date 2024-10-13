#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
   public:
    HumanA(string name, Weapon& weapon);
    ~HumanA();
    void attack();

   private:
    string _name;
    Weapon& _weapon;
};

#endif  // HUMANA_HPP