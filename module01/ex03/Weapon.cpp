#include "Weapon.hpp"

Weapon::Weapon() : _type("") {};
Weapon::Weapon(const string &type) : _type(type) {};
Weapon::~Weapon() {};

// getType() returns a const reference to type

/**
 * @brief get the type of the weapon
 *
 * getType() const : marks the getType()as a const member function
 * guarantees the function will not modify any member variables of the Weapon instance
 * Declaring a member function with const allows it to be called on const instances of the class
 * allowing flexibility for accessing class members in a read-only manner
 *
 * @return const string&  : ensures that the returned string reference to _type
 * cannot be used to modify _type
 * Protects the internal _type member from being altered by any external function that calls getType()
 *
 */
const string& Weapon::getType() const {
    return _type;
};

// setType() sets type using the new one passed as parameter
void Weapon::setType(string type) {
    this->_type = type;
};
