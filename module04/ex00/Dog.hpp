#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

// Deprived class
class Dog : public Animal {
   public:
    Dog();
    // Dog(const std::string& type);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    virtual void makeSounds() const;
};

#endif