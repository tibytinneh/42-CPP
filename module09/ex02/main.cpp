#include <sys/time.h>

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "PmergeMe.hpp"
static inline double wall_us() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec * 1e6 + tv.tv_usec;
}

int main(int ac, char** av) {
    if (ac < 2) {
        std::cerr << "Error: insufficient arguments." << std::endl;
        return (EXIT_FAILURE);
    }

    PmergeMe pm;

    try {
        pm.buildContainers(ac, av);
        pm.printVector("Before:", pm.getVector());
        double v0 = wall_us();  // wall-clock microseconds.
        pm.sort_vector(/*trace=*/false);
        double v1 = wall_us();
        double vec_us = v1 - v0;
        double d0 = wall_us();
        pm.sort_deque(/*trace=*/false);
        double d1 = wall_us();
        double deq_us = d1 - d0;
        pm.printVector("After: ", pm.getVector());
        //        pm.printDeque("After(d):", pm.getDeque());
        std::cout.setf(std::ios::fixed);
        std::cout << std::setprecision(5);
        std::cout << "Time to process a range of " << pm.size()
                  << " elements with std::vector : " << vec_us << " us\n";
        std::cout << "Time to process a range of " << pm.size()
                  << " elements with std::deque  : " << deq_us << " us\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
