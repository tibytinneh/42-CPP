#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "[WrongAnimal] default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
    std::cout << "[WrongAnimal] param constructor called. " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
    std::cout << "[WrongAnimal] copy constructor called. " << other.type << " has been copied." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
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

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] makes sound." << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}