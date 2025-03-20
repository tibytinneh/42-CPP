#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// Deprived class
class Dog : public Animal {
   private:
    Brain* brain;

   public:
    Dog();
    Dog(const std::string& type);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    virtual void makeSound() const;
};

#endif