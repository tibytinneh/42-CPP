#include "AForm.hpp"

#include <stdexcept>

#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("default"), _signed(false), _signGrade(50), _executeGrade(50), _target("default_target") {}

AForm::AForm(std::string const &name, int signGrade, int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &a) : _name(a._name), _signed(a._signed), _signGrade(a._signGrade), _executeGrade(a._executeGrade) {
}

AForm &AForm::operator=(const AForm &a) {
    if (this != &a)
        this->_signed = a._signed;
    return *this;
}

AForm::~AForm() {
}

std::string AForm::getName() const { return _name; }
bool AForm::getSigned() const { return _signed; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecuteGrade() const { return _executeGrade; }
std::string AForm::getTarget() const { return _target; }

void AForm::beSigned(Bureaucrat &o) {
    if (o.getGrade() > _signGrade) {
        std::cout << o.getName() << " couldn't sign " << AForm::getName() << " because ";
        throw GradeTooLowException();
        // main.cpp will print out Error with e.what();
    } else {
        _signed = true;
        std::cout << "\033[34m" << o.getName() << " signed " << AForm::getName() << "\033[0m" << std::endl;
    }
}

void AForm::validateExecution(Bureaucrat const &executor) const {
    if (!this->_signed) {
        throw std::runtime_error("Cannot execute: form is not signed.");
    }
    if (executor.getGrade() > this->_executeGrade) {
        throw AForm::GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &b) {
    std::cout << b.getName() << ", AForm sign: " << std::boolalpha << b.getSigned()
              << ", AForm sign grade: " << b.getSignGrade()
              << ", AForm execute grade: " << b.getExecuteGrade()
              << "." << std::endl;
    return out;
}
