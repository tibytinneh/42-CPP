#include "HumanB.hpp"

HumanB::HumanB(string name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::attack() {
    if (_weapon) {
        cout << _name << " attacks with their " << C_YELLOW << _weapon->getType() << C_DEFAULT << endl;
    } else {
        cout << _name << C_RED << "has no weapon!" << C_DEFAULT << endl;
    }
}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
};