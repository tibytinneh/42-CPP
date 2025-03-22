#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "[Cat] default constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "[Cat] copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);  // base class assignment
    }
    std::cout << "[Cat] copy assignment constructor called." << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] destructor called." << std::endl;
}
/*--------------------PUBLIC METHODS--------------------*/

void Cat::makeSound() const {
    std::cout << "[Cat] MEOWS." << std::endl;
}