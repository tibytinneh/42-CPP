#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Utils.hpp"

void testForm(AForm &form, Bureaucrat &signer, Bureaucrat &executor) {
    std::cout << form;

    try {
        announceGreen("Attempting to sign form");
        signer.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << "Signing failed: " << e.what() << std::endl;
    }

    try {
        announceGreen("Attempting to execute form");
        executor.executeForm(form);
    } catch (const std::exception &e) {
        std::cerr << "Execution failed: " << e.what() << std::endl;
    }

    announceLine();
}

int main() {
    std::srand(std::time(NULL));  // for robotomy randomness

    {
        announceStartLine();
        announceRed("ShrubberyCreationForm test");

        Bureaucrat signer("LowRank", 145);
        Bureaucrat executor("ShrubExec", 137);
        ShrubberyCreationForm shrub("garden");

        testForm(shrub, signer, executor);

        announceEndLine();
    }

    {
        announceStartLine();
        announceRed("RobotomyRequestForm test");

        Bureaucrat signer("MidRank", 72);
        Bureaucrat executor("RoboExec", 45);
        RobotomyRequestForm robo("target");

        testForm(robo, signer, executor);
        testForm(robo, signer, executor);  // test twice to check randomness

        announceEndLine();
    }

    {
        announceStartLine();
        announceRed("PresidentialPardonForm test");

        Bureaucrat signer("President", 25);
        Bureaucrat executor("Beeblebrox", 5);
        PresidentialPardonForm pardon("Ford Prefect");

        testForm(pardon, signer, executor);

        announceEndLine();
    }

    {
        announceStartLine();
        announceRed("Failure: Execute without signing");

        Bureaucrat signer("SignFail", 1);
        Bureaucrat executor("ExecFail", 1);
        ShrubberyCreationForm failForm("void");

        try {
            executor.executeForm(failForm);
        } catch (const std::exception &e) {
            std::cerr << "Expected failure: " << e.what() << std::endl;
        }

        announceEndLine();
    }

    {
        announceStartLine();
        announceRed("Failure: Grade too low to execute");

        Bureaucrat signer("StrongSigner", 1);
        Bureaucrat weakExec("Weakling", 150);
        PresidentialPardonForm form("Marvin");

        testForm(form, signer, weakExec);

        announceEndLine();
    }

    return 0;
}
