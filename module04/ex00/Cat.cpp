#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "[Cat] default constructor called." << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type) {
    this->type = type;
    std::cout << "[Cat] param constructor called." << std::endl;
}

Cat::Cat(const Cat& other) {
    *this = other;
    std::cout << "[Cat] copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);  // base class assignment
        this->type = other.type;   // explicitly copying type
    }
    std::cout << "[Cat] copy assignment constructor called." << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] destructor called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "[Cat] MEOWS." << std::endl;
}