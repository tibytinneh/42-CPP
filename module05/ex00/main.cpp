#include <iostream>

#include "Bureaucrat.hpp"

int main() {
    {
        try {
            Bureaucrat jeff("Jeff", 151);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Jeff's creation: " << e.what() << std::endl;
        }

        std::cout << "------------------------" << std::endl;

        try {
            Bureaucrat jeremy("Jeremy", 0);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught during Jeremy's creation: " << e.what() << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }
    {
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
