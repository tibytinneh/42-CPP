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
    std::cout << "\n--------------------------------------" << std::endl;
    {
        announceBlue("Creating a dog: Dog dog1;");
        Dog dog1;
        dog1.setType("I AM A HELLA DOG");
        std::cout << dog1.getType() << " " << std::endl;

        announceBlue("Copy constructor: Dog dog2(dog1);");
        Dog dog2(dog1);
        std::cout << dog2.getType() << " " << std::endl;

        announceBlue("Assignment constructor: Dog dog3; dog3 = dog1;");
        Dog dog3;
        dog3 = dog1;
        std::cout << dog3.getType() << " " << std::endl;

        std::cout << "\n--------------------------------------" << std::endl;
        dog1.setType("UWU");

        std::cout << dog1.getType() << " " << std::endl;
        std::cout << dog2.getType() << " " << std::endl;

        std::cout << "\n--------------------------------------" << std::endl;

        const Animal* animalDog = new Dog();
        animalDog->makeSound();
        delete animalDog;
    }
    return 0;
}