#include "WrongDog.hpp"

WrongDog::WrongDog() {
    type = "WrongDog";
    std::cout << "[WrongDog] default constructor called." << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {
    std::cout << "[WrongDog] copy constructor called." << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
    std::cout << "[WrongDog] copy assignment constructor called." << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);  // base class assignment
    }
    return *this;
}

WrongDog::~WrongDog() {
    std::cout << "[WrongDog] destructor called." << std::endl;
}

/*--------------------PUBLIC METHODS--------------------*/
void WrongDog::makeSound() const {
    std::cout << "[WrongDog] BARKS." << std::endl;
}