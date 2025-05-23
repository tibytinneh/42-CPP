#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "[Dog] default constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "[Dog] copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] copy assignment constructor called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);  // base class assignment
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] destructor called." << std::endl;
}

/*--------------------PUBLIC METHODS--------------------*/
void Dog::makeSound() const {
    std::cout << "[Dog] BARKS." << std::endl;
}