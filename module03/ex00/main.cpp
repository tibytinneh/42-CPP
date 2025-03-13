#include "ClapTrap.hpp"
#include "Utils.hpp"

int main() {
    announceBlue("default constructor");
    ClapTrap test;
    std::cout << &test;
    test.printAll();

    announceBlue("string constructor ct1(\"Apple\")");
    ClapTrap ct1("Apple");
    std::cout << &ct1;
    ct1.printAll();

    announceBlue("string constructor ct2(\"Bob\")");
    ClapTrap ct2("Bob");
    std::cout << &ct2;
    ct2.printAll();

    announceRed("ct1.attack(ct2.getName); ct2.takeDamage(ct1.getAttackDamage);");
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());

    ct1.printAll();
    ct2.printAll();

    announceRed("9* ct1.attack(ct2.getName); ct2.takeDamage(ct1.getAttackDamage);");

    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());

    ct1.printAll();
    ct2.printAll();

    announceRed("ct1.attack(ct2.getName); ct2.takeDamage(ct1.getAttackDamage);");
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());

    ct1.printAll();
    ct2.printAll();

    announceGreen("ct1.beRepaired(5); ct2.beRepaired(5);");
    ct1.beRepaired(5);
    ct2.beRepaired(5);
    ct1.printAll();
    ct2.printAll();
    std::cout << "\n--------------------------------------" << std::endl;

    announceBlue("copy constructor test ClapTrap ct3(ct2)");

    ClapTrap ct3(ct2);
    std::cout << &ct2;
    ct2.printAll();
    std::cout << &ct3;
    ct3.printAll();
    announceBlue("ct3.setName(\"Coconut\")");
    ct3.setName("Coconut");
    std::cout << &ct2;
    ct2.printAll();
    std::cout << &ct3;
    ct3.printAll();

    //    ClapTrap(const ClapTrap& other);             // copy constructor
    //  ClapTrap& operator=(const ClapTrap& other);  // copy assignment constructor
    announceBlue("ClapTrap ct4;");

    ClapTrap ct4;
    std::cout << &ct3;
    ct3.printAll();
    std::cout << &ct4;
    ct4.printAll();
    announceBlue("copy assignment constructor test ct4 = ct3;");

    ct4 = ct3;
    std::cout << &ct3;
    ct3.printAll();
    std::cout << &ct4;
    ct4.printAll();
    announceBlue("ct4.setName(\"Dolphin\")");
    ct4.setName("Dolphin");
    std::cout << &ct3;
    ct3.printAll();
    std::cout << &ct4;
    ct4.printAll();

    return 0;
}