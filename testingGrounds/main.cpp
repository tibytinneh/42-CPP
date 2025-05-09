#include <exception>
#include <iostream>

#include "Utils.hpp"

class exceptionTrue : public std::exception {
   private:
    const char* message;

   public:
    exceptionTrue(const char* message) : message(message) {};

    virtual const char* what() const throw() {
        return message;
    }
};

class exceptionFalse : public std::exception {
   private:
    const char* message;

   public:
    exceptionFalse(const char* message) : message(message) {};

    virtual const char* what() const throw() {
        return message;
    }
};

int main() {
    // int i = 0;
    exceptionTrue e("TRUE!");
    exceptionFalse a("FALSE!");
    try {
        if (1 + 1 != 2) {
            throw e;
        } else {
            throw a;
        }
    } catch (exceptionTrue ex) {
        std::cout << ex.what();
    } catch (exceptionFalse ex) {
        std::cout << ex.what();
    }

    return 0;
}