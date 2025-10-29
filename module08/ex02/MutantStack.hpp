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

// deprive from std::stack<T, Container>
// clang-format off
template <typename T, typename Container = std::deque<T> >
// clang-format on
class MutantStack : public std::stack<T, Container>
{
public:
    /*  OCF */
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack &o) : std::stack<T, Container>(o) {}
    MutantStack &operator=(const MutantStack &o)
    {
        if (this != &o)
            std::stack<T, Container>::operator=(o);
        return *this;
    }
    ~MutantStack() {}

    /* Forward and reverse iterators*/
    // iterator typedefs to allow calling MutantStack<int>::iterator etc
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};