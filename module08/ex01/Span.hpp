#pragma once

/*
    Span is the absolute distance between two stored integer
    longestSpan() => maximum possible distance between any two numbers.
        basically max - min.
            - find the min element
            - find the max element
            - return max - min

    shortestSpan() => minimum possible distance between any two numbers.
        - make tmp copy
        - sort tmp cpy
        - go from left to right, computing sorted[i+1]- sorted[i]
            keep the minimum
            if zero can just ORD

*/

/*
    iterators are like bookmarks
    a type of object that acts like am ovable pointer into a container.
    we create a variable of that ierator type to point at a specific position.

    type: std::vector<int>::iterator
    variable: std::vector<int>::iterator it;
*/

#include <vector>
#include <algorithm> // std::sort, std::min_element, std::max_element
#include <stdexcept>
#include <limits> //std::numeric_limits

class Span
{

public:
    // public iterator typedefs
    // lets users write Span::iterator it without knowing we're using vector.
    typedef std::vector<int>::iterator iterator;
    typedef std::vector<int>::const_iterator const_iterator;

    // ocf
    explicit Span(unsigned int n);
    Span(const Span &o);
    Span &operator=(const Span &o);
    ~Span();

public:
    // getters
    unsigned int getN() const; // fixed capacity
    unsigned int size() const; // current count. vector::size()

    // mod
    void addNumber(int val); // add a single element to the vector

    // range
    // bulk insert using an iterator range
    // just like vector::insert(first, last)
    //           vector::insert(v.begin(), v.end())
    // addNumber checks for capacity then push_back(val)

    template <typename I>
    void addRange(I first, I last)
    {
        for (; first != last; first++)
            addNumber(*first);
    }

    // span
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    // iterators
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

private:
    unsigned int _n;
    std::vector<int> _data;
};