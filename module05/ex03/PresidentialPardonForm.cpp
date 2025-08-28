#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5, target)
{
    // Constructor implementation can initialize any additional members if needed
    // For example, you might want to initialize a member variable with the target
    // Here, we assume that the Form class constructor initializes the name, sign grade, and execute grade.
    // No additional initialization needed for this example
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : AForm(a)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
    if (this != &a)
    {
        AForm::operator=(a);
        // Copy the necessary members from 'a' to 'this'
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    validateExecution(executor);
    action();
}