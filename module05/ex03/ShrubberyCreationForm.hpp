#pragma once
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    void action() const;
    ShrubberyCreationForm(); // so cannot call

public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &a);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
    ~ShrubberyCreationForm();

    /**------------helper function------------*/
    void execute(Bureaucrat const &executor) const;
};