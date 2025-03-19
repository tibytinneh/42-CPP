#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] default constructor called." << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
    std::cout << "[Animal] param constructor called. " << type << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "[Animal] copy constructor called. " << other.type << " has been copied." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type = other.type;

    } else {
        std::cout << "Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] default destructor called." << std::endl;
}

void Animal::makeSound() const {
    std::cout << "[Animal] makes sound." << std::endl;
}