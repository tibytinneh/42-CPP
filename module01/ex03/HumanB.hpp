#include "Weapon.hpp"

class Human {
   private:
    std::string _name;
    Weapon* _weapon;

   public:
    Human(string name);
    ~Human();

    void attack();
};