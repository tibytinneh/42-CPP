#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon& weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack() {
    cout << _name << " attacks with their " << C_YELLOW << _weapon.getType() << C_DEFAULT << std::endl;
}
