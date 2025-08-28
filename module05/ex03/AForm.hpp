#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _executeGrade;
    std::string _target;

protected:
    void validateExecution(Bureaucrat const &executor) const;
    virtual void action() const = 0;

public:
    AForm();
    AForm(std::string const &name, int signGrade, int executeGrade);
    AForm(std::string const &name, int signGrade, int executeGrade, std::string const &target);
    AForm(const AForm &a);
    AForm &operator=(const AForm &a);
    virtual ~AForm();

    /*--------------------Getters--------------------*/
    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    std::string getTarget() const;

    /*--------------------Helper functions--------------------*/
    void beSigned(Bureaucrat &o);
    virtual void execute(Bureaucrat const &executor) const = 0;

    /*--------------------Exception Classes--------------------*/
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &b);