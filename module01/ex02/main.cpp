#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

#define C_RED "\033[31m"
#define C_BLUE "\033[34m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_DEFAULT "\033[0m"

int main()
{
    string stringVAR = "HI THIS IS BRAIN";
    string *stringPTR = &stringVAR;
    string &stringREF = stringVAR;

    cout << C_RED
         << "string stringVAR = \"HI THIS IS BRAIN\";" << endl
         << "string* stringPTR = &stringVAR;" << endl
         << "string& stringREF = stringVAR;" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << C_BLUE;
    cout << "Memory address of stringVAR: " << &stringVAR << endl;
    cout << "Memory address held by stringPTR: " << stringPTR << endl;
    cout << "Memory address held by stringREF: " << &stringREF << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << C_GREEN;
    cout << "Value of stringVAR: " << stringVAR << endl;
    cout << "Value pointed by stringPTR: " << *stringPTR << endl;
    cout << "Value pointed by stringREF: " << stringREF << endl;

    return 0;
}

/* Pointers vs References
Pointers holds the memory address of another variable.
References are like aliases - limited af pointers.

References:
Complusory to initialize reference at the time of declaration.
Can't be reassigned.
Can't be initialized to NULL.
Can't create array of reference
Can't create reference to reference.
Can't have a pointer to reference but can point to what the reference aliases.
(Shares the same memory address as the object it references.)

Automatically dereferences (no * needed)


Ideal for aliasing variables, pass-by-reference, and avoiding copy overhead with simpler syntax
*/