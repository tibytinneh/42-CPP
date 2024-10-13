#include "HumanA.hpp"

Human::Human(string name, Weapon* weapon) : _name(name), _weapon(weapon) {}
Human::~Human() {
    if (_weapon)
        delete _weapon;
}

void Human::attack() {
    cout << _name << " attacks with their " << C_YELLOW << _weapon->getType() << C_DEFAULT << std::endl;
}
