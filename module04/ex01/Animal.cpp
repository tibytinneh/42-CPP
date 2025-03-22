#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] default constructor called." << std::endl;
}

Animal::Animal(const std::string& t) {
    std::cout << "[Animal] param constructor called. " << type << std::endl;
    this->type = t;
}

Animal::Animal(const Animal& other) {
    std::cout << "[Animal] copy constructor called. " << other.type << " has been copied." << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] copy assignment constructor called. " << other.type << " has been copied." << std::endl;
    if (this != &other) {
        this->type = other.type;
    } else {
        std::cout << "[Animal] Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] default destructor called." << std::endl;
}

/*--------------------PUBLIC METHODS--------------------*/
void Animal::makeSound() const {
    std::cout << "[Animal] makes sound." << std::endl;
}

/*--------------------GETTERS--------------------*/
std::string Animal::getType() const {
    return this->type;
}