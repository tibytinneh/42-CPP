#include "Weapon.hpp"

Weapon::Weapon();
Weapon::Weapon(string weapon) { _type(weapon) };
Weapon::~Weapon();

// getType() returns a const reference to type
const string& Weapon::getType() {
    return _type;
};
// setType() sets type using the new one passed as parameter
void Weapon::setType(string type) {
    this->_type = type;
};
