#include <string>
#include <iostream>


using std::cout;
using std::endl;


std::string stringVAR = "HI THIS IS BRAIN";
std::string*                stringPTR = &stringVAR;
std::string& stringREF = *stringVAR;

int main()
{
    cout << "Memory address of stringVAR: " << &stringVAR << endl;
    cout << "Memory address held by stringPTR: " << stringPTR << endl;
    cout << "Memory address held by stringREF: " << stringREF << endl;

    cout << "Value of stringVAR: " << stringVAR << endl;
    cout << "Value pointed by stringPTR: " << *stringPTR << endl;
    cout << "Value pointed by stringREF: " << *stringREF << endl;

    return 0;
}
