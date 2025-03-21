#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// Base class
class Animal {
   protected:
    std::string type;

   public:
    Animal();
    Animal(const std::string& type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal() = 0;

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif
