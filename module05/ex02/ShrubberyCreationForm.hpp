#pragma once
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   protected:
    void action() const;

   public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &a);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
    ~ShrubberyCreationForm();

    /**------------helper function------------*/
    void execute(Bureaucrat const &executor) const;
};