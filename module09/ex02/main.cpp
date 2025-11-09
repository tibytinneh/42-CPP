#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: insufficient arguments." << std::endl;
        return (EXIT_FAILURE);
    }

    PmergeMe pm;

    try
    {
        pm.buildContainers(ac, av);
        const std::vector<unsigned int> og_v = pm.getVector();
        pm.printVector("Before:", og_v);
        // run step 1: swap pairs for v & d
        // pm.swap_pairs();
        // pm.printVector("after swap pairs(v):", pm.getVector());
        // pm.printDeque("after swap pairs(d):", pm.getDeque());
        // clang-format off
        pm.sort_vector(/*trace=*/true);
        pm.sort_deque(/*trace=*/true);
        // std::vector<std::vector<unsigned int> > mainV, pEndV;
        // std::vector<unsigned int> remainderV;
        // pm.build_chains_vector(mainV, pEndV, remainderV, /*trace=*/true);
        pm.printVector("After(v):", pm.getVector());
        pm.printDeque("After(d):", pm.getDeque());

    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}