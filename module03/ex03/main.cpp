#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "Utils.hpp"

int main() {
    announceBlue("FragTrap default constructor");
    FragTrap test;
    std::cout << &test;
    test.printAll();

    announceBlue("FragTrap string constructor ft1(\"Apple\")");
    FragTrap ft1("Apple");
    std::cout << &ft1;
    ft1.printAll();

    announceBlue("FragTrap string constructor ft2(\"Bob\")");
    FragTrap ft2("Bob");
    std::cout << &ft2;
    ft2.printAll();

    announceRed("ft1.attack(ft2.getName); ft2.takeDamage(ft1.getAttackDamage);");
    ft1.attack(ft2.getName());
    ft2.takeDamage(ft1.getAttackDamage());

    ft1.printAll();
    ft2.printAll();

    announceRed("4* ft1.attack(ft2.getName); ft2.takeDamage(ft1.getAttackDamage);");
    ft1.attack(ft2.getName());
    ft2.takeDamage(ft1.getAttackDamage());
    ft1.attack(ft2.getName());
    ft2.takeDamage(ft1.getAttackDamage());
    ft1.attack(ft2.getName());
    ft2.takeDamage(ft1.getAttackDamage());
    ft1.attack(ft2.getName());
    ft2.takeDamage(ft1.getAttackDamage());
    ft1.printAll();
    ft2.printAll();

    announceRed("ft1.attack(ft2.getName); ft2.takeDamage(ft1.getAttackDamage);");
    ft1.attack(ft2.getName());
    ft2.takeDamage(ft1.getAttackDamage());

    ft1.printAll();
    ft2.printAll();

    announceGreen("ft1.beRepaired(5); ft2.beRepaired(5);");
    ft1.beRepaired(5);
    ft2.beRepaired(5);
    ft1.printAll();
    ft2.printAll();

    announceGreen("ft1.highFivesGuys(); ft2.beRepaired(5);");
    ft1.highFivesGuys();
    ft2.highFivesGuys();
    std::cout << "\n--------------------------------------" << std::endl;

    announceBlue("copy constructor test FragTrap ft3(ft2)");

    FragTrap ft3(ft2);
    std::cout << &ft2;
    ft2.printAll();
    std::cout << &ft3;
    ft3.printAll();
    announceBlue("ft3.setName(\"Coconut\")");
    ft3.setName("Coconut");
    std::cout << &ft2;
    ft2.printAll();
    std::cout << &ft3;
    ft3.printAll();

    announceBlue("FragTrap ft4;");
    FragTrap ft4;
    std::cout << &ft3;
    ft3.printAll();
    std::cout << &ft4;
    ft4.printAll();
    announceBlue("copy assignment constructor test ft4 = ft3;");

    ft4 = ft3;
    std::cout << &ft3;
    ft3.printAll();
    std::cout << &ft4;
    ft4.printAll();
    announceBlue("ft4.setName(\"Dolphin\")");
    ft4.setName("Dolphin");
    std::cout << &ft3;
    ft3.printAll();
    std::cout << &ft4;
    ft4.printAll();

    return 0;
}