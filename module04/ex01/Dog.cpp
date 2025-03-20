#include "Dog.hpp"

Dog::Dog() {
    std::cout << "[Dog] default constructor called." << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const std::string& type) : Animal(type) {
    this->type = type;
    std::cout << "[Dog] param constructor called." << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "[Dog] copy constructor called." << std::endl;
    brain = new Brain(*other.brain);  // deep copy
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] copy assignment constructor called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);         // base class assignment (copy base class attributes)
        delete brain;                     // prevent memleaks
        brain = new Brain(*other.brain);  // deep copy of brain
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] destructor called." << std::endl;
    delete brain;
}

/*--------------------PUBLIC METHODS--------------------*/
void Dog::makeSound() const {
    std::cout << "[Dog] BARKS." << std::endl;
}

/*--------------------Getters and setters--------------------*/
void Dog::setBrainIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
    return brain->getIdea(index);
}