#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Utils.hpp"
int main() {
    std::cout << "\n--------------------------------------" << std::endl;

    {
        announceBlue("Create and fill an array of Animal objects");
        Animal* ptr[100];
        announceBlue("Half of it will be Dog objects and ther other half will be Cat objects");
        for (int i = 0; i < 50; i++) {
            ptr[i] = new Dog();
        }
        for (int i = 50; i < 100; i++) {
            ptr[i] = new Cat();
        }

        announceBlue("At the end of your program execution, loop over this array and delete every Animal.");
        for (int i = 0; i < 100; i++) {
            delete ptr[i];
        }
    }
    std::cout << "\n--------------------------------------" << std::endl;
    {
        announceGreen("TESTS with Animal, Cat, Dog.");
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();  // will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    return 0;
}