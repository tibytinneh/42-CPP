#include "Dog.hpp"

Dog::Dog() {
    std::cout << "[Dog] default constructor called." << std::endl;
}

// Dog::Dog(const std::string& type) : type(type) {
//     std::cout << "[Dog] param constructor called." << std::endl;
// }

Dog::Dog(const Dog& other) {
    *this = other;
    std::cout << "[Dog] copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    *this = other;
    std::cout << "[Dog] copy assignment constructor called." << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] destructor called." << std::endl;
}

void Dog::makeSounds() const {
    std::cout << "[Dog] BARKS." << std::endl;
}