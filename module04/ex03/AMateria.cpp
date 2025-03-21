#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "[AMateria] constructor called." << std::endl;
}
AMateria::AMateria(const std::string type) : type(type) {
    std::cout << "[AMateria] param constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}
AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
AMateria::~AMateria() {
    std::cout << "[AMateria] Destructor called." << std::endl;
};

/*-------------------- Getters and setters --------------------*/
std::string const& AMateria::getType() const {
    return this->type;
}

/*-------------------- Public member functions --------------------*/

AMateria* AMateria::clone() const {}
void AMateria::use(ICharacter& target) {}