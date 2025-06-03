#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
   private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _executeGrade;

   public:
    Form();
    Form(std::string const name, const int signGrade, const int executeGrade);
    Form(const Form &a);
    Form &operator=(const Form &a);
    ~Form();

    /*--------------------Getters--------------------*/
    std::string getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    /*--------------------Helper functions--------------------*/
    void beSigned(Bureaucrat &o);
    void execute(Bureaucrat const &executor) const = 0;

    /*--------------------Exception Classes--------------------*/
    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &b);