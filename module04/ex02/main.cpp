#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Utils.hpp"
int main() {
    std::cout << "\n--------------------------------------" << std::endl;

    {
        announceBlue("Create and fill an array of Animal objects");
        Animal* ptr[4] = {NULL, NULL, NULL, NULL};
        announceBlue("Half of it will be Dog objects and ther other half will be Cat objects");
        for (int i = 0; i < 2; i++) {
            ptr[i] = new Dog();
        }
        for (int i = 2; i < 4; i++) {
            ptr[i] = new Cat();
        }

        announceBlue("At the end of your program execution, loop over this array and delete every Animal.");

        for (int i = 0; i < 4; i++) {
            if (ptr[i] != NULL) {  // prevents deleting uninitialized memory
                delete ptr[i];
            }
        }
    }
    std::cout << "\n--------------------------------------" << std::endl;
    {
        // UNCOMMENT TO TEST PURE VIRTUAL
        // const Animal* meta = new Animal();
        // meta->makeSound();
        // delete meta;
        announceGreen("TESTS with Animal, Cat, Dog.");
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();  // will output the cat sound!
        j->makeSound();
        delete j;
        delete i;
    }
    std::cout << "\n--------------------------------------" << std::endl;
    {
        announceBlue("Deep copy.");
        Dog dog1;
        dog1.setBrainIdea(0, "ORIGINAL ONE");
        dog1.setBrainIdea(1, "ORIGINAL TWO");

        announceGreen("Dog dog2 = dog1;");
        Dog dog2 = dog1;

        std::cout << "dog1's first idea: " << dog1.getBrainIdea(0) << std::endl;
        std::cout << "dog2's first idea: " << dog2.getBrainIdea(0) << std::endl;  // Should still be "Chase the cat"

        announceGreen("Modifying dog1's ideas[0]");
        dog1.setBrainIdea(0, "NEW ONE");

        std::cout << "dog1's first idea: " << dog1.getBrainIdea(0) << std::endl;
        std::cout << "dog2's first idea: " << dog2.getBrainIdea(0) << std::endl;  // Should still be "Chase the cat"

        announceRed("Going out of scope.");
        dog1.makeSound();
    }
    return 0;
}