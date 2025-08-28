#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Utils.hpp"
#include "AForm.hpp"

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
        announceStartLine();
        {
            announceRed("TESTING: ShrubberyCreationForm [valid case]");

            Bureaucrat sign("SIGN", 145);
            Bureaucrat execute("EXECUTE", 137);
            ShrubberyCreationForm target("TREE");

            testForm(target, sign, execute);
        }
        announceLine();
        {
            announceRed("TESTING: ShrubberyCreationForm [invalid case: signing grade too low]");

            Bureaucrat sign("SIGN", 150);
            Bureaucrat execute("EXECUTE", 137);
            ShrubberyCreationForm target("TREE");

            testForm(target, sign, execute);
        }
        announceLine();
        {
            announceRed("TESTING: ShrubberyCreationForm [invalid case: execution grade too low]");

            Bureaucrat sign("SIGN", 145);
            Bureaucrat execute("EXECUTE", 150);
            ShrubberyCreationForm target("TREE");

            testForm(target, sign, execute);
        }
        announceEndLine();
    }

    {
        announceStartLine();
        {
            announceRed("TESTING: RobotomyRequestForm [valid case]");

            Bureaucrat sign("SIGN", 72);
            Bureaucrat execute("EXECUTE", 45);
            RobotomyRequestForm target("ROBOT");

            testForm(target, sign, execute);

            announceRed("TESTING: execute multiple times to check randomness");
            execute.executeForm(target);
            execute.executeForm(target);
            execute.executeForm(target);
            execute.executeForm(target);
            execute.executeForm(target);
            execute.executeForm(target);
        }
        announceLine();
        {
            announceRed("TESTING: RobotomyRequestForm [invalid case: signing grade too low]");

            Bureaucrat sign("SIGN", 150);
            Bureaucrat execute("EXECUTE", 45);
            RobotomyRequestForm target("ROBOT");

            testForm(target, sign, execute);
        }
        announceLine();
        {
            announceRed("TESTING: RobotomyRequestForm[invalid case: execution grade too low]");

            Bureaucrat sign("SIGN", 72);
            Bureaucrat execute("EXECUTE", 150);
            RobotomyRequestForm target("ROBOT");

            testForm(target, sign, execute);
        }
        announceEndLine();
    }
    {
        announceStartLine();
        {
            announceRed("TESTING: PresidentialPardonForm [valid case]");

            Bureaucrat sign("SIGN", 25);
            Bureaucrat execute("EXECUTE", 5);
            PresidentialPardonForm target("teoenming");

            testForm(target, sign, execute);
        }
        announceLine();
        {
            announceRed("TESTING: PresidentialPardonForm [invalid case: signing grade too low]");

            Bureaucrat sign("SIGN", 150);
            Bureaucrat execute("EXECUTE", 5);
            PresidentialPardonForm target("teoenming");

            testForm(target, sign, execute);
        }
        announceLine();
        {
            announceRed("TESTING: PresidentialPardonForm [invalid case: execution grade too low]");

            Bureaucrat sign("SIGN", 25);
            Bureaucrat execute("EXECUTE", 150);
            PresidentialPardonForm target("teoenming");

            testForm(target, sign, execute);
        }
        announceEndLine();
    }

    announceEnd();
    return 0;
}
