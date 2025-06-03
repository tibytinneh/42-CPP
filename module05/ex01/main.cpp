#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Utils.hpp"

int main() {
    {
        announceStartLine();
        announceRed("Bureaucrat OCF");
        announce("[Bureaucrat] Tests the copy constructor and copy assignment");
        announceGreen("Copy constructor");
        Bureaucrat og("og", 42);
        Bureaucrat cpy(og);

        std::cout << "Original: " << og;
        std::cout << "Copy: " << cpy;
        std::cout << "---" << std::endl;

        announceGreen("Copy assignment");
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
        announceRed("Form OCF");
        announce("[Form] Tests the copy constructor and copy assignment");
        announceGreen("Copy constructor");
        Form og("OG", 42, 42);
        Form cpy(og);

        std::cout << "Original: " << og;
        std::cout << "Copy: " << cpy;
        std::cout << "---" << std::endl;

        announceGreen("Copy assignment");
        Form a("A", 42, 42);
        Form b("B", 24, 24);
        Bureaucrat c("C", 42);

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
        announceRed("[Form] class construction: grade too high/low---");
        try {
            announceGreen("[Form] with valid grade - Apple, signGrade: 50, executeGrade: 50");
            Form apple("Apple", 50, 50);
            std::cout << apple;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Apple's creation: " << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        try {
            announceGreen("[Form] with invalid grade - Bear, signGrade: 0, executeGrade: 50");
            Form bear("Bear", 0, 50);
            std::cout << bear;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Bear's creation: " << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        try {
            announceGreen("[Form] with invalid grade - Cute, signGrade: 150, executeGrade: 50");
            Form cute("Cute", 151, 50);
            std::cout << cute;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Cute's creation: " << e.what() << std::endl;
        }
        announceEndLine();
    }
    {
        announceStartLine();
        announceRed("[Form] class function: beSigned()");
        try {
            announceGreen("[Form] Apple, signGrade: 50, executeGrade: 50");
            Form apple("Apple", 50, 50);
            announceGreen("[Bureaucrat] Bob, Grade: 50");
            Bureaucrat bob("Bob", 50);
            std::cout << apple;
            std::cout << bob;
            announceGreen("apple.beSigned(bob);");
            apple.beSigned(bob);

            std::cout << apple;
            std::cout << bob;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        announceEndLine();
    }
    {
        announceStartLine();
        announceRed("[Form] class function: beSigned(), but grade too low");
        try {
            announceGreen("[Form] Apple, signGrade: 50, executeGrade: 50");
            Form apple("Apple", 50, 50);
            announceGreen("[Bureaucrat] Bob, Grade: 100");
            Bureaucrat bob("Bob", 100);
            std::cout << apple;
            std::cout << bob;
            announceGreen("apple.beSigned(bob);");
            apple.beSigned(bob);

            std::cout << apple;
            std::cout << bob;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        announceEndLine();
    }
    {
        announceStartLine();
        announceRed("[Form] class function: signForm()");
        try {
            announceGreen("[Form] Apple, signGrade: 50, executeGrade: 50");
            Form apple("Apple", 50, 50);
            announceGreen("[Bureaucrat] Bob, Grade: 50");
            Bureaucrat bob("Bob", 50);
            announceGreen("bob.signForm(apple);");
            bob.signForm(apple);
            std::cout << apple;
            std::cout << bob;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "---" << std::endl;
        announceEndLine();
    }
    {
        announceStartLine();
        announceRed("[Form] class function: signForm(), but grade too low");
        try {
            announceGreen("[Form] Apple, signGrade: 50, executeGrade: 50");
            Form apple("Apple", 50, 50);
            announceGreen("[Bureaucrat] Bob, Grade: 100");
            Bureaucrat bob("Bob", 100);
            announceGreen("bob.signForm(apple);");
            bob.signForm(apple);
            std::cout << apple;
            std::cout << bob;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        announceEndLine();
    }

    return 0;
}
