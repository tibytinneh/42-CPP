#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "[WrongAnimal] default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "[WrongAnimal] copy constructor called. " << other.type << " has been copied." << std::endl;
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "[WrongAnimal] copy assignment constructor called. " << other.type << " has been copied." << std::endl;
    if (this != &other) {
        this->type = other.type;
    } else {
        std::cout << "[WrongAnimal] Self-assignment prevented; Cannot assign object to itself." << std::endl;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] default destructor called." << std::endl;
}

/*--------------------PUBLIC METHODS--------------------*/
void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] makes sound." << std::endl;
}

/*--------------------GETTERS--------------------*/
std::string WrongAnimal::getType() const {
    return this->type;
}