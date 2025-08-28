#pragma once
#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    void action() const;
    RobotomyRequestForm(); // so cannot call

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &a);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
    ~RobotomyRequestForm();

    /**------------helper function------------*/
    void execute(Bureaucrat const &executor) const;
};