#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "constructorcalledwithoutanything" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
    std::cout << "constructorcalledwithparameters" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &a) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::GradeTooHighException() {
    return "Grade is too high!";
}

Bureaucrat::GradeTooHighException() {
    return "Grade is too high!";
}