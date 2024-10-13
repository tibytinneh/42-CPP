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

class Weapon {
   public:
    Weapon();
    Weapon(string weapon);
    ~Weapon();

    // getType() returns a const reference to type
    const string& getType();
    // setType() sets type using the new one passed as parameter
    void setType(string type);

   private:
    string _type;
};