#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "[WrongCat] default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "[WrongCat] copy assignment constructor called." << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);  // base class assignment
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] destructor called." << std::endl;
}

/*--------------------PUBLIC METHODS--------------------*/
void WrongCat::makeSound() const {
    std::cout << "[WrongCat] MEOWS." << std::endl;
}