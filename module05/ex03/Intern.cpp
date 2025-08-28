#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}
Intern::~Intern() {}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    AForm *(Intern::*formCreators[3])(const std::string &target) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm};

    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            announceGreen("Intern creates " + formName + " form");
            return (this->*formCreators[i])(target);
        }
    }

    announceRed("Error: invalid form name:'" + formName + "'");
    announceRed("Valid form names: 'shrubbery creation', 'robotomy request', 'presidential pardon'");
    return NULL;
}
