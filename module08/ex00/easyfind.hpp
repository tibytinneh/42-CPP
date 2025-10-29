/*
    Function template that accepts a type T. Takes two parameters, type T and integer.
    Function has to find the first occurrence of the second pararmeter in the first parameter.
    If no occurrence is found, either throw or return an error value of your choice.
    //wtf is associative container

*/
/*
    std::find takes 3 arguments:
        first: an iterator to the beginning of the range to search
        last: an iterator to the end of the range (one past the last element)
        value: the value to search for.
    return success:
        iterator to the first element in the range.
    return fail:
        return to  `last` aka container.end()
*/

/* iterator and const_iterator are both member typedefs (type aliases) provided by most container classes
    eg: std::vector<int>::iterator and std::vector<int>::const_iterator are types defined inside std::vector<int>
*/

/* easyfind is a free (non-member) function template that uses the container's existing iterators and std::find.
    it wraps the usal pattern container.begin()/container.end()/std::find into a single reusable function.
    TLDR SHORTCUT THE THING

    without:
        for (int x = 5; x <= 10; ++x) {
        std::vector<int>::iterator it = std::find(v.begin(), v.end(), x);
        if (it != v.end())
            std::cout << "found " << x << " at index " << std::distance(v.begin(), it) << "\n";
        else
            std::cout << x << " not found\n";
    }

    with:
        for (int x = 5; x <= 10; ++x) {
        std::vector<int>::iterator it = easyfind(v, x); // returns std::vector<int>::iterator
        if (it != v.end())
            std::cout << "found " << x << " at index " << std::distance(v.begin(), it) << "\n";
        else
            std::cout << x << " not found\n";
    }
*/

#pragma once

#include <algorithm> //for STL ALGORITHM std::find

// non-const overload - return iterator to first match or contaier.end() if not found

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    return std::find(container.begin(), container.end(), value);
}

// const overload - return const iterator to first match or contaier.end() if not found
template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
    return std::find(container.begin(), container.end(), value);
}