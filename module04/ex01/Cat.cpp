#include "Cat.hpp"

Cat::Cat() {
    std::cout << "[Cat] default constructor called." << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const std::string& type) : Animal(type) {
    this->type = type;
    std::cout << "[Cat] param constructor called." << std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "[Cat] copy constructor called." << std::endl;
    brain = new Brain(*other.brain);  // deep copy
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] copy assignment constructor called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);         // base class assignment (copy base class attributes)
        delete brain;                     // prevent memleaks
        brain = new Brain(*other.brain);  // deep copy of brain
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] destructor called." << std::endl;
    delete brain;
}
/*--------------------PUBLIC METHODS--------------------*/

void Cat::makeSound() const {
    std::cout << "[Cat] MEOWS." << std::endl;
}

/*--------------------Getters and setters--------------------*/
void Cat::setBrainIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const {
    return brain->getIdea(index);
}