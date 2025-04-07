#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
    std::string const &getName();
    int getGrade();

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

#endif