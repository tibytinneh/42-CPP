#pragma once

#include <stack>
#include <deque>

//    std::deque    -   A double-ended queue that allows effection insertion and deletion at both the front and back, also provides random access
//    std::stack    - A LIFO (last in first out) data structure, implemented using std::deque or std::list as its underlying container
//                          LIFO: [a][b][c][d][e(top)] <->push/pop
//                  defined in header <stack>
//                  template<class T, class Container = std::deque<T>> class stack;
/*
    make std::stack iterable.
    butcher the original stack to create missing features.

        - implement in terms of a std::stack
            public inherit std::stack
        - offer all its member functions, plus iterators
            => OCF
            => iterators and reverse iterators
            */

// clang-format off
template <typename T>
// clang-format on
class MutantStack : public std::stack<T>
{
public:
    /*  OCF */
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &o) : std::stack<T>(o) {}
    MutantStack &operator=(const MutantStack &o)
    {
        if (this != &o)
            std::stack<T>::operator=(o);
        return *this;
    }
    ~MutantStack() {}

    /* Forward and reverse iterators*/
    // iterator typedefs to allow calling MutantStack<int>::iterator etc

    typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::reverse_iterator reverse_iterator;
    typedef typename container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};