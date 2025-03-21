#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character {
   public:
    Character();
    Character(const std::string);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    /*-------------------- Public member functions --------------------*/
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif