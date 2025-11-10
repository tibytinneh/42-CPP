#pragma once

#include <stack>

//    std::deque    -   A double-ended queue that allows effection insertion and deletion at both the front and back, also provides random access
//    IS  A SEQUENCE CONTAINER.
//
//    std::stack    - A LIFO (last in first out) data structure, implemented using std::deque or std::list as its underlying container
//      IS A CONTIANER ADAPTER.
//                          LIFO: [a][b][c][d][e(top)] <->push/pop
//                  defined in header <stack>
//                  template<class T> class stack;
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
class MutantStack : public std::stack<T> {
   public:
    /*  OCF */
    MutantStack();
    MutantStack(const MutantStack& o);
    MutantStack& operator=(const MutantStack& o);
    ~MutantStack();

    /* Forward and reverse iterators*/
    // iterator typedefs to allow calling MutantStack<int>::iterator etc

    typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::reverse_iterator reverse_iterator;
    typedef typename container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rbegin();
    reverse_iterator rend();

    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"