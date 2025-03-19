#include "Animal.hpp"
#include "Dog.hpp"

int main() {
    {
        Animal a;
    }
    std::cout << "\n--------------------------------------" << std::endl;
    {
        const Animal* meta = new Animal();

        meta->makeSound();
        delete meta;
    }
    std::cout << "\n--------------------------------------" << std::endl;
    {
        const Animal* j = new Dog();
        j->makeSound();
        delete j;
    }

    std::cout << "\n--------------------------------------" << std::endl;
    std::cout << "\n--------------------------------------" << std::endl;
    std::cout << "\n--------------------------------------" << std::endl;
    return 0;
}