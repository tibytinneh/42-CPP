#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
        announceRed("Form OCF test");
        announceGreen("Copy constructor test");
        Form og("OG", 42, 42);
        Form cpy(og);

        std::cout << "Original: " << og << std::endl;
        std::cout << "Copy: " << cpy << std::endl;
        std::cout << "---" << std::endl;

        announceGreen("Copy assignment test");
        Form a("A", 42, 42);
        Form b("B", 24, 24);
        Bureaucrat c("C", 42);
        a.beSigned(c);

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
        announceGreen("Test for grade too high/low");
        try {
            Form apple("Apple", 50, 50);
            std::cout << apple << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Apple's creation: " << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        try {
            Form bear("Bear", 0, 50);
            std::cout << bear << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Bear's creation: " << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        try {
            Form cute("Cute", 151, 50);
            std::cout << cute << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Cute's creation: " << e.what() << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }
    {
        announceGreen("Test for beSigned");
        try {
            Form apple("Apple", 50, 50);
            Bureaucrat bob("Bob", 50);
            std::cout << apple << std::endl;
            std::cout << bob << std::endl;
            apple.beSigned(bob);

            std::cout << apple << std::endl;
            std::cout << bob << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
    }
    {
        announceGreen("Test for beSigned, but grade too low");
        try {
            Form apple("Apple", 50, 50);
            Bureaucrat bob("Bob", 100);
            std::cout << apple << std::endl;
            std::cout << bob << std::endl;
            apple.beSigned(bob);

            std::cout << apple << std::endl;
            std::cout << bob << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
    }
    {
        announceGreen("Test for signForm");
        try {
            Form apple("Apple", 50, 50);
            Bureaucrat bob("Bob", 50);
            bob.signForm(apple);
            std::cout << apple << std::endl;
            std::cout << bob << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
    }
    {
        announceGreen("Test for signForm, but grade too low");
        try {
            Form apple("Apple", 50, 50);
            Bureaucrat bob("Bob", 100);
            bob.signForm(apple);
            std::cout << apple << std::endl;
            std::cout << bob << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
    }

    return 0;
}
