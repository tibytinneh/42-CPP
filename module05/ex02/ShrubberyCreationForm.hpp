#pragma once
#include <string>

#include "AForm.hpp"

class ShubberyCreationForm : public AForm {
   protected:
    void action() const;

   public:
    ShubberyCreationForm();
    ShubberyCreationForm(const ShubberyCreationForm &a);
    ShubberyCreationForm &operator=(const ShubberyCreationForm &a);
    ~ShubberyCreationForm();

    /**------------helper function------------*/
    void execute(Bureaucrat const &executor) const;
};