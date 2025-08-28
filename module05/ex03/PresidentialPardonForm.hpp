#pragma once
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    void action() const;
    PresidentialPardonForm(); // so cannot call

public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &a);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &a);
    ~PresidentialPardonForm();

    /**------------helper function------------*/
    void execute(Bureaucrat const &executor) const;
};