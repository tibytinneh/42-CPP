#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#define C_RED "\033[31m"
#define C_BLUE "\033[34m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_DEFAULT "\033[0m"

// getType() returns a const reference to type
// setType() sets type using the new one passed as parameter
class Weapon {
   public:
    Weapon();
    Weapon(string type);
    ~Weapon();

    const string &getType() const;
    void setType(string type);

   private:
    string _type;
};

#endif  // WEAPON_HPP