#include <iostream>
#include "Base.hpp"

// prints the actual type of the object pointed to by p. "A", "B", or "C"
//** with a class pointer: safely test dynamic_cast*/
//** (dynamic_cast<CLASS *)(p) return success = non-null. return fail = null; */

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

// prints the actual type of the object referenced by p. "A", "B" or "C".
// forbidden: using a pointer inside this function.

//** with a class reference*/
//** (void)(dynamic_cast)<A &>(p) throws a std::bad_cast exception if the type doesnt match */

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception &)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception &)
    {
    }
}
