#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// Deprived class
class Cat : public Animal {
   private:
    Brain* brain;

   public:
    Cat();
    Cat(const std::string& type);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const;
};

#endif