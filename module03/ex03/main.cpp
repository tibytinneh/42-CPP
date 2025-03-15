#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "Utils.hpp"

int main() {
    announceBlue("DiamondTrap default constructor");
    DiamondTrap test;
    std::cout << &test;
    test.printAll();
    test.whoAmI();

    announceBlue("DiamondTrap string constructor dt1(\"Apple\")");
    DiamondTrap dt1("Apple");
    std::cout << &dt1;
    dt1.printAll();
    dt1.whoAmI();

    announceBlue("DiamondTrap string constructor dt2(\"Bob\")");
    DiamondTrap dt2("Bob");
    std::cout << &dt2;
    dt2.printAll();

    announceRed("dt1.attack(dt2.getName); dt2.takeDamage(dt1.getAttackDamage);");
    dt1.attack(dt2.getName());
    dt2.takeDamage(dt1.getAttackDamage());

    dt1.printAll();
    dt2.printAll();

    announceRed("3* dt1.attack(dt2.getName); dt2.takeDamage(dt1.getAttackDamage);");
    dt1.attack(dt2.getName());
    dt2.takeDamage(dt1.getAttackDamage());
    dt1.attack(dt2.getName());
    dt2.takeDamage(dt1.getAttackDamage());
    dt1.attack(dt2.getName());
    dt2.takeDamage(dt1.getAttackDamage());
    dt1.printAll();
    dt2.printAll();

    announceRed("dt1.attack(dt2.getName); dt2.takeDamage(dt1.getAttackDamage);");
    dt1.attack(dt2.getName());
    dt2.takeDamage(dt1.getAttackDamage());

    dt1.printAll();
    dt2.printAll();

    announceGreen("dt1.beRepaired(5); dt2.beRepaired(5);");
    dt1.beRepaired(5);
    dt2.beRepaired(5);
    dt1.printAll();
    dt2.printAll();

    announceGreen("dt1.highFivesGuys(); dt2.beRepaired(5);");
    dt1.highFivesGuys();
    dt2.highFivesGuys();
    announceGreen("dt2.printGateStatus();");
    dt2.printGateStatus();
    announceGreen("dt2.guardGate();");
    dt2.guardGate();
    announceGreen("dt2.printGateStatus();");
    dt2.printGateStatus();
    announceGreen("dt2.guardGate();");
    dt2.guardGate();
    announceGreen("dt2.printGateStatus();");
    dt2.printGateStatus();
    announceGreen("dt2.guardGate();");
    dt2.guardGate();
    announceGreen("dt2.printGateStatus();");
    dt2.printGateStatus();
    announceGreen("dt2.guardGate();");
    dt2.guardGate();
    announceGreen("dt2.printGateStatus();");
    dt2.printGateStatus();

    std::cout << "\n--------------------------------------" << std::endl;

    announceBlue("copy constructor test DiamondTrap dt3(dt2)");

    DiamondTrap dt3(dt2);
    std::cout << &dt2;
    dt2.printAll();
    std::cout << &dt3;
    dt3.printAll();
    announceBlue("dt3.setName(\"Coconut\")");
    dt3.setName("Coconut");
    std::cout << &dt2;
    dt2.printAll();
    std::cout << &dt3;
    dt3.printAll();

    announceBlue("DiamondTrap dt4;");
    DiamondTrap dt4;
    std::cout << &dt3;
    dt3.printAll();
    std::cout << &dt4;
    dt4.printAll();
    announceBlue("copy assignment constructor test dt4 = dt3;");

    dt4 = dt3;
    std::cout << &dt3;
    dt3.printAll();
    std::cout << &dt4;
    dt4.printAll();
    announceBlue("dt4.setName(\"Dolphin\")");
    dt4.setName("Dolphin");
    std::cout << &dt3;
    dt3.printAll();
    std::cout << &dt4;
    dt4.printAll();

    return 0;
}