#pragma once

#include <exception>
#include <iostream>
#include <string>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
   private:
    const std::string _name;
    int _grade;

   public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(const Bureaucrat &a);
    Bureaucrat &operator=(const Bureaucrat &a);
    ~Bureaucrat();

    /*--------------------Getters--------------------*/
    const std::string getName() const;
    int getGrade() const;

    /*--------------------Helper functions--------------------*/

    void incrementGrade();
    void decrementGrade();

    /*--------------------Exception Classes--------------------*/
    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);