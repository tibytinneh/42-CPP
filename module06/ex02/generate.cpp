// randomly instantiates A, B, or C and returns the class instance as a Base pointer.
// use anything for random choice implementation

#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base *generate(void)
{

    std::srand(std::time(NULL));
    int rng = std::rand() % 3;

    if (rng == 0)
        return new A;
    else if ((rng == 1))
        return new B;
    else
        return new C;
}