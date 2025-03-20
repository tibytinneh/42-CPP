#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Utils.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
int main() {
    std::cout << "\n--------------------------------------" << std::endl;
    {
        announceRed("Using a Base Class pointer.");
        announceBlue("j is a pointer to Animal, pointing to a Dog object.");
        announceBlue("since makeSound() is virtual, function call is resolved at runtime (dynamic binding), maintaining a virtual table.");
        announceGreen("when calling j->makeSound(), vtable looks up Dog::makeSound().");
        const Animal* j = new Dog();
        j->makeSound();
        std::cout << j->getType() << std::endl;
        delete j;
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
    std::cout << "\n--------------------------------------" << std::endl;
    {
        announceRed("TESTS with WrongAnimal, WrongCat, WrongDog.");
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* j = new WrongDog();
        const WrongAnimal* i = new WrongCat();
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