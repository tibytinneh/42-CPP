#include "Weapon.hpp"

class Human {
   private:
    std::string _name;
    Weapon* _weapon;

   public:
    Human(string name, Weapon* weapon);
    ~Human();

    void attack();
};
