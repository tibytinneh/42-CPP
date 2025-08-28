#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Utils.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void testForm(AForm &form, Bureaucrat &signer, Bureaucrat &executor)
{
    // announceLine();
    std::cout << form;

    try
    {
        announceGreen("Attempting to sign form");
        signer.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Signing failed: " << e.what() << std::endl;
    }

    try
    {
        announceGreen("Attempting to execute form");
        executor.executeForm(form);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution failed: " << e.what() << std::endl;
    }

    // announceLine();
}

int main()
{
    announceStart();
    {
        {
            announceRed("TESTING: testcase from PDF");

            Intern someRandomIntern;
            AForm *rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            delete rrf;
        }
        announceStartLine();
        {
            announceRed("TESTING: Intern creates ShrubberyCreationForm [valid case]");
            Intern bob;
            Bureaucrat sign("SIGN", 1);
            Bureaucrat execute("EXECUTE", 1);
            AForm *tree = bob.makeForm("shrubbery creation", "TREE");
            if (tree)
                testForm(*tree, sign, execute);
            delete tree;
        }
        announceLine();
        {
            announceRed("TESTING: Intern creates RobotomyRequestForm [valid case]");

            Intern bob;
            Bureaucrat sign("SIGN", 1);
            Bureaucrat execute("EXECUTE", 1);
            AForm *robot = bob.makeForm("robotomy request", "ROBOT");
            if (robot)
                testForm(*robot, sign, execute);
            delete robot;
        }
        announceLine();
        {
            announceRed("TESTING: Intern creates PresidentialPardonForm [valid case]");
            Intern bob;
            Bureaucrat sign("SIGN", 1);
            Bureaucrat execute("EXECUTE", 1);
            AForm *president = bob.makeForm("presidential pardon", "teoenming");
            if (president)
                testForm(*president, sign, execute);
            delete president;
        }
        announceLine();
        {
            announceRed("TESTING: Intern creates [invalid case]");
            Intern bob;
            Bureaucrat sign("SIGN", 1);
            Bureaucrat execute("EXECUTE", 1);
            AForm *fail = bob.makeForm("namamama", "teoenming");
            if (fail)
            {
                testForm(*fail, sign, execute);
                delete fail;
            }
        }

        announceEndLine();
    }
    announceEnd();
    return 0;
}
