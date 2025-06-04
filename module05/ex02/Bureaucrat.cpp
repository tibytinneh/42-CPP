#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &a) : _name(a._name), _grade(a._grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a) {
    if (this != &a) {
        this->_grade = a._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const {
    return _name;
};

int Bureaucrat::getGrade() const {
    return _grade;
};

void Bureaucrat::incrementGrade() {
    if (_grade > HIGHEST_GRADE) {
        _grade -= 1;
    } else {
        throw Bureaucrat::GradeTooHighException();
    }
}
void Bureaucrat::decrementGrade() {
    if (_grade < LOWEST_GRADE) {
        _grade += 1;
    } else {
        throw Bureaucrat::GradeTooLowException();
    }
}
void Bureaucrat::signForm(AForm &form) {
    form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->getName() << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return out;
}
