#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Utils.hpp"

int main() {
    {
        announce(GREEN, "---START: Bureaucrat OCF test---");
        announce(DEFAULT, "Copy constructor test");
        Bureaucrat og("og", 42);
        Bureaucrat cpy(og);

        std::cout << "Original: " << og << std::endl;
        std::cout << "Copy: " << cpy << std::endl;
        std::cout << "---" << std::endl;

        announce(DEFAULT, "Copy assignment test");
        Bureaucrat a("A", 42);
        Bureaucrat b("B", 24);

        announce(DEFAULT, "before assignment");
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "---" << std::endl;
        announce(DEFAULT, "after assignment");
        b = a;
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        announce(RED, "---END: Bureaucrat OCF test---");
    }
    {
        announce(GREEN, "---START: Form OCF test---");
        announce(DEFAULT, "Copy constructor test");
        Form og("OG", 42, 42);
        Form cpy(og);

        std::cout << "Original: " << og << std::endl;
        std::cout << "Copy: " << cpy << std::endl;
        std::cout << "---" << std::endl;

        announce(DEFAULT, "Copy assignment test");
        Form a("A", 42, 42);
        Form b("B", 24, 24);
        Bureaucrat c("C", 42);
        a.beSigned(c);

        announce(DEFAULT, "before assignment");
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "---" << std::endl;
        announce(DEFAULT, "after assignment");
        b = a;
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        announce(RED, "---END: Form OCF test---");
    }
    {
        announce(GREEN, "---START: Test for construction of Form class: grade too high/low---");
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
        announce(RED, "---END: Test for construction of Form class: grade too high/low---");
    }
    {
        announce(GREEN, "---START: Test for form's function: beSigned()---");
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
        announce(GREEN, "Test for beSigned, but grade too low");
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
        announce(GREEN, "Test for signForm");
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
        announce(GREEN, "Test for signForm, but grade too low");
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
