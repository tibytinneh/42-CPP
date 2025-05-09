#include <iostream>

#include "Bureaucrat.hpp"
#include "Utils.hpp"

int main() {
    {
        announceRed("Bureaucrat OCF test");
        announceGreen("Copy constructor test");
        Bureaucrat og("og", 42);
        Bureaucrat cpy(og);

        std::cout << "Original: " << og << std::endl;
        std::cout << "Copy: " << cpy << std::endl;
        std::cout << "---" << std::endl;

        announceGreen("Copy assignment test");
        Bureaucrat a("A", 42);
        Bureaucrat b("B", 24);

        announceGreen("before assignment");
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "---" << std::endl;
        announceGreen("after assignment");
        b = a;
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    {
        std::cout << "Test for grade too high/low" << std::endl;
        try {
            Bureaucrat apple("Apple", 50);
            std::cout << apple << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Apple's creation: " << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        try {
            Bureaucrat jeremy("Jeremy", 0);
            std::cout << jeremy << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Jeremy's creation: " << e.what() << std::endl;
        }

        std::cout << "---" << std::endl;
        try {
            Bureaucrat jeff("Jeff", 151);
            std::cout << jeff << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Jeff's creation: " << e.what() << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }
    {
        std::cout << "Test for grade too low/high when incrementing" << std::endl;
        try {
            Bureaucrat amanda("Amanda", 2);
            std::cout << amanda << std::endl;
            amanda.incrementGrade();
            std::cout << amanda << std::endl;
            amanda.incrementGrade();
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << "------------------------" << std::endl;
        try {
            Bureaucrat banana("Banana", 149);
            std::cout << banana << std::endl;
            banana.decrementGrade();
            std::cout << banana << std::endl;
            banana.decrementGrade();
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }
    return 0;
}
