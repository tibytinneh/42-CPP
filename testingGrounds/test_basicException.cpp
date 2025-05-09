#include <exception>
#include <iostream>

#include "Utils.hpp"

class myException : public std::exception {
    virtual const char* what() const throw() {
        return "user defined exception";
    }
};

int main() {
    // int i = 0;
    myException e;
    try {
        throw e;
    } catch (std::exception& ex) {
        std::cout << ex.what();
    }

    return 0;
}