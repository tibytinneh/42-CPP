#include "ClapTrap.hpp"
#include "Utils.hpp"

int main() {
    announceBlue("default constructor");
    ClapTrap test;
    test.printAll();

    announceBlue("string constructor ct1(\"Apple\")");
    ClapTrap ct1("Apple");
    ct1.printAll();

    announceBlue("string constructor ct2(\"Bob\")");
    ClapTrap ct2("Bob");
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
    return 0;
}