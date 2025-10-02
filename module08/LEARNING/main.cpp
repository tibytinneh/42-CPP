// initialize the iterator by assigningsome valid iterator

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // FKIN C++98 INITIALIZER LISTS FOR STD::VECTOR NOT SUPPORTED
    //    std::vector<int> v = {1, 2, 3, 4, 5};

    std::vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    // an iterator in C++ is a pointer-like object that points to an element of the STL container.
    // used to loop through the contents of the STL container in C++
    // they make the STL algorithms independent of the type of container used.
    // we can just pass the iterator to the container elements, instead of the container itself to the STL algorithms.

    // each container in C++ STL has its own iterator.
    // declare an iterator as:
    //  <type>::iterator it;
    //     type: type of container for which the iterator is declared.
    //     it: name assigned to iterator object.

    std::vector<int>::iterator first = v.begin();
    std::vector<int>::iterator last = v.end();

    std::cout << "value from dereferencing v.begin(): " << *first << std::endl;
    std::cout << "value from dereferencing v.end() - 1: " << *(last - 1) << std::endl;
    std::cout << "[UNDEFINED BEHAVIOUR] value from dereferencing v.end(): " << *last << std::endl;

    while (first != last) {
        std::cout << *first << " ";
        first++;
    }

    std::vector<int>::iterator helpla = std::find_if(v.begin(), v.end(), Iseven());

    return 0;
}