#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "Utils.hpp"

int main() {
    {
        announceBlue("ScavTrap default constructor");
        ScavTrap test;
        std::cout << &test;
        test.printAll();
    }
    {
        std::cout << "\n--------------------------------------" << std::endl;
        announceBlue("ClapTrap vs ScavTrap");
        ClapTrap test2("CLAPONE");
        ClapTrap test3("CLAPTWO");

        test2.ClapTrap::attack(test3.getName());

        ScavTrap test4("SCAVONE");
        ScavTrap test5("SCAVTWO");
        test4.ScavTrap::attack(test5.getName());
    }

    {
        std::cout << "\n--------------------------------------" << std::endl;
        announceBlue("ScavTrap string constructor st1(\"Apple\")");
        ScavTrap st1("Apple");
        std::cout << &st1;
        st1.printAll();

        announceBlue("ScavTrap string constructor st2(\"Bob\")");
        ScavTrap st2("Bob");
        std::cout << &st2;
        st2.printAll();

        announceRed("st1.attack(st2.getName); st2.takeDamage(st1.getAttackDamage);");
        st1.attack(st2.getName());
        st2.takeDamage(st1.getAttackDamage());

        st1.printAll();
        st2.printAll();

        announceRed("4* st1.attack(st2.getName); st2.takeDamage(st1.getAttackDamage);");
        st1.attack(st2.getName());
        st2.takeDamage(st1.getAttackDamage());
        st1.attack(st2.getName());
        st2.takeDamage(st1.getAttackDamage());
        st1.attack(st2.getName());
        st2.takeDamage(st1.getAttackDamage());
        st1.attack(st2.getName());
        st2.takeDamage(st1.getAttackDamage());
        st1.printAll();
        st2.printAll();

        announceRed("st1.attack(st2.getName); st2.takeDamage(st1.getAttackDamage);");
        st1.attack(st2.getName());
        st2.takeDamage(st1.getAttackDamage());

        st1.printAll();
        st2.printAll();

        announceGreen("st1.beRepaired(5); st2.beRepaired(5);");
        st1.beRepaired(5);
        st2.beRepaired(5);
        st1.printAll();
        st2.printAll();
        std::cout << "\n--------------------------------------" << std::endl;

        announceBlue("copy constructor test ScavTrap st3(st2)");

        ScavTrap st3(st2);
        std::cout << &st2;
        st2.printAll();
        std::cout << &st3;
        st3.printAll();
        announceBlue("st3.setName(\"Coconut\")");
        st3.setName("Coconut");
        std::cout << &st2;
        st2.printAll();
        std::cout << &st3;
        st3.printAll();

        announceBlue("ScavTrap st4;");
        ScavTrap st4;
        std::cout << &st3;
        st3.printAll();
        std::cout << &st4;
        st4.printAll();
        announceBlue("copy assignment constructor test st4 = st3;");

        st4 = st3;
        std::cout << &st3;
        st3.printAll();
        std::cout << &st4;
        st4.printAll();
        announceBlue("st4.setName(\"Dolphin\")");
        st4.setName("Dolphin");
        std::cout << &st3;
        st3.printAll();
        std::cout << &st4;
        st4.printAll();

        announceGreen("st4.printGateStatus();");
        st4.printGateStatus();
        announceGreen("std::cout << st4.guardGate();");
        st4.guardGate();
        announceGreen("st4.printGateStatus();");
        st4.printGateStatus();
        announceGreen("std::cout << st4.guardGate();");
        st4.guardGate();
        announceGreen("st4.printGateStatus();");
        st4.printGateStatus();
        announceGreen("std::cout << st4.guardGate();");
        st4.guardGate();
        announceGreen("st4.printGateStatus();");
        st4.printGateStatus();
        announceGreen("std::cout << st4.guardGate();");
        st4.guardGate();
        announceGreen("st4.printGateStatus();");
        st4.printGateStatus();

        return 0;
    }
}