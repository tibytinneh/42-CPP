#include "WrongDog.hpp"

WrongDog::WrongDog() {
    type = "WrongDog";
    std::cout << "[WrongDog] default constructor called." << std::endl;
}

WrongDog::WrongDog(const std::string& type) : WrongAnimal(type) {
    this->type = type;
    std::cout << "[WrongDog] param constructor called." << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) {
    *this = other;
    std::cout << "[WrongDog] copy constructor called." << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);  // base class assignment
        this->type = other.type;        // explicitly copying type
    }
    std::cout << "[WrongDog] copy assignment constructor called." << std::endl;
    return *this;
}

WrongDog::~WrongDog() {
    std::cout << "[WrongDog] destructor called." << std::endl;
}

void WrongDog::makeSound() const {
    std::cout << "[WrongDog] BARKS." << std::endl;
}