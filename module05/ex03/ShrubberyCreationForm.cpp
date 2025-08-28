#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target)
{
    // Constructor implementation can initialize any additional members if needed
    // For example, you might want to initialize a member variable with the target
    // Here, we assume that the Form class constructor initializes the name, sign grade, and execute grade.
    // No additional initialization needed for this example
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : AForm(a)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
    if (this != &a)
    {
        AForm::operator=(a);
        // Copy the necessary members from 'a' to 'this'
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
    std::string filename = this->getTarget() + "_shrubbery";
    // std::ios
    std::ofstream o(filename.c_str());
    if (!o)
    {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }

    o << "      /\n";
    o << "    /    \\\n";
    o << "   /      \\\n";
    o << "  /        \\\n";
    o << " /__________\\\n";
    o << "      l l\n";
    o << "      l l\n";
    o.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    validateExecution(executor);
    action();
}
