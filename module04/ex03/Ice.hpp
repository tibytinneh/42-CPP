#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
   public:
    Ice();  // default constructor
    // Ice(std::string const & type);
    Ice(const Ice& other);             // copy constructor
    Ice& operator=(const Ice& other);  // copy assignment operator
    virtual ~Ice();
    Amateria Ice* clone() const;

    virtual void use(ICharacter& target);
};