#include <iostream>

#include "Bureaucrat.hpp"
#include "Utils.hpp"

int main() {
    {
        announceStartLine();
        announceRed("Bureaucrat OCF test");
        announceGreen("Copy constructor test");
        Bureaucrat og("og", 42);
        Bureaucrat cpy(og);

        std::cout << "Original: " << og;
        std::cout << "Copy: " << cpy;
        std::cout << "---" << std::endl;

        announceGreen("Copy assignment test");
        Bureaucrat a("A", 42);
        Bureaucrat b("B", 24);

        announceGreen("before assignment");
        std::cout << "a: " << a;
        std::cout << "b: " << b;
        std::cout << "---" << std::endl;
        announceGreen("after assignment");
        b = a;
        std::cout << "a: " << a;
        std::cout << "b: " << b;
        announceEndLine();
    }

    {
        announceStartLine();
        announceRed("Test for grade too high/low");
        announceGreen("Constructing: Apple, grade: 50");
        try {
            Bureaucrat apple("Apple", 50);
            std::cout << apple;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Apple's creation: " << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        announceGreen("Constructing: Jeremy, grade: 0");
        try {
            Bureaucrat jeremy("Jeremy", 0);
            std::cout << jeremy;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Jeremy's creation: " << e.what() << std::endl;
        }

        announceGreen("Constructing: Jeff, grade: 151");
        std::cout << "---" << std::endl;
        try {
            Bureaucrat jeff("Jeff", 151);
            std::cout << jeff;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Jeff's creation: " << e.what() << std::endl;
        }

        announceEndLine();
    }
    {
        announceStartLine();
        announceRed("Test for grade too low/high when incrementing");

        try {
            announceGreen("Constructing: Amanda, grade: 2");
            Bureaucrat amanda("Amanda", 2);
            std::cout << amanda;
            announceGreen("Incrementing: Amanda");
            amanda.incrementGrade();
            std::cout << amanda;
            announceGreen("Incrementing: Amanda");
            amanda.incrementGrade();
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        announceLine();
        try {
            announceGreen("Constructing: Banana, grade: 149");
            Bureaucrat banana("Banana", 149);
            std::cout << banana;
            announceGreen("Decrementing: Banana");
            banana.decrementGrade();
            std::cout << banana;
            announceGreen("Decrementing: Banana");
            banana.decrementGrade();
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        announceEndLine();
    }
    return 0;
}
