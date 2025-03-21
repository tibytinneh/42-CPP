#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class AMateria {
   protected:
    std::string type;

   public:
    AMateria();
    AMateria(const std::string type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria() = 0;

    /*-------------------- Getters and setters --------------------*/
    std::string const& getType() const;  // returns materia type

    /*-------------------- Public member functions --------------------*/

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif  // AMateria