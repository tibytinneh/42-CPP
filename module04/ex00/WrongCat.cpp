#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "[WrongCat] default constructor called." << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type) {
    this->type = type;
    std::cout << "[WrongCat] param constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    *this = other;
    std::cout << "[WrongCat] copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);  // base class assignment
        this->type = other.type;        // explicitly copying type
    }
    std::cout << "[WrongCat] copy assignment constructor called." << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] destructor called." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "[WrongCat] MEOWS." << std::endl;
}