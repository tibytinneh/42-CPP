#include <iostream>
#include <string>

#include "Array.hpp"

int main() {
    {
        std::cout << "default constructor empty array" << std::endl;
        Array<int> a;
        std::cout << a;
    }

    {
        std::cout << "constructor unsigned int n 4 default init" << std::endl;
        Array<int> a(4);
        Array<int> b(a);
        Array<int> c = a;
        std::cout << a;
        std::cout << b;
        std::cout << c;
        std::cout << "increment a by 1 (check deep copy)" << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            a[i]++;
        std::cout << a;
        std::cout << b;
        std::cout << c;

        std::cout << "check bounds std::exception throwing a[4];" << std::endl;
        try {
            (void)a[4];
        } catch (const std::exception& e) {
            std::cout << "caught exception:" << e.what() << std::endl;
        }

        std::cout << "check deep copy but size change" << std::endl;
        Array<int> d(1);
        std::cout << d;
        d = a;
        std::cout << d;

        std::cout << "test const overload subscript []" << std::endl;
        const Array<int> f = a;
        std::cout << f;
        int z = f[0];
        std::cout << z << std::endl;
        try {
            (void)f[4];
        } catch (const std::exception& e) {
            std::cout << "caught exception:" << e.what() << std::endl;
        }
    }

    {
        std::cout << "test with string T" << std::endl;
        Array<std::string> a(3);
        std::cout << a;
        try {
            a[0] = "apple";
            a[1] = "bb";
            a[2] = "caca";
            a[3] = "lmao";
        } catch (std::exception& e) {
            std::cout << "caught exception: " << e.what() << std::endl;
        }
        std::cout << a;
    }
}
