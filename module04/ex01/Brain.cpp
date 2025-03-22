#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] constructor called." << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] copy constructor called." << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] copy assignment constructor called." << std::endl;
    if (this != &other) {
        // *this = other; //too shallow, need to go inside array.
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] destructor called." << std::endl;
}

/*--------------------Getters and setters--------------------*/
void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}
