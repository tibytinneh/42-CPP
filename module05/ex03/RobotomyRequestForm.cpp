#include "RobotomyRequestForm.hpp"

#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target)
{
    srand(time(NULL));
    // Constructor implementation can initialize any additional members if needed
    // For example, you might want to initialize a member variable with the target
    // Here, we assume that the Form class constructor initializes the name, sign grade, and execute grade.
    // No additional initialization needed for this example
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : AForm(a)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
    if (this != &a)
    {
        AForm::operator=(a);
        // Copy the necessary members from 'a' to 'this'
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const
{

    std::cout << "\033[33m" << "DRILLING NOISES..." << "\033[0m" << std::endl;
    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed on " << this->getTarget() << "." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    validateExecution(executor);
    action();
}
