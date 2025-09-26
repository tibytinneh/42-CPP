#include "Base.hpp"
#include <iostream>

Base *generate();
void identify(Base *p);
void identify(Base &p);

int main()
{

    Base *base = generate();

    std::cout << "rng base is generated ";
    std::cout << std::endl;

    std::cout << "identify(base);" << std::endl
              << "via pointer: " << std::endl;
    identify(base);

    std::cout << "identify(*base);" << std::endl
              << "via reference: " << std::endl;
    identify(*base);

    delete base;
    return 0;
}