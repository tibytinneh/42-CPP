#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(50), _executeGrade(50) {
}

Form::Form(std::string const name, const int signGrade, const int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
        throw GradeTooLowException();
}

Form::Form(const Form &a) : _name(a._name), _signed(a._signed), _signGrade(a._signGrade), _executeGrade(a._executeGrade) {
}

Form &Form::operator=(const Form &a) {
    if (this != &a)
        this->_signed = a._signed;
    return *this;
}

Form::~Form() {
}

std::string Form::getName() const {
    return _name;
};

bool Form::getSigned() const {
    return _signed;
};

int Form::getSignGrade() const {
    return _signGrade;
};

int Form::getExecuteGrade() const {
    return _executeGrade;
};

void Form::beSigned(Bureaucrat &o) {
    if (o.getGrade() > _signGrade) {
        std::cout << o.getName() << " couldn't sign " << Form::getName() << " because ";
        throw GradeTooLowException();
        // main.cpp will print out Error with e.what();
    } else {
        _signed = true;
        std::cout << "\033[34m" << o.getName() << " signed " << Form::getName() << "\033[0m" << std::endl;
    }
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &b) {
    std::cout << b.getName() << ", Form sign: " << std::boolalpha << b.getSigned()
              << ", Form sign grade: " << b.getSignGrade()
              << ", Form execute grade: " << b.getExecuteGrade()
              << "." << std::endl;
    return out;
}
