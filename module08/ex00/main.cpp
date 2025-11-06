/*
* Sequential containers:
    Stores elements in a linear sequence. Maintaining the order of insertion.
    std::vector -   A dynamic array that can grow or shrink in size. Provides random access to elements and efficient insertion/deletion at the end.
    std::deque  -   A double-ended queue that allows effection insertion and deletion at both the front and back, also provides random access
    std::list   -   a doubly-linked list that provides efficient insertion and deletion anywhere within the list, but does not provide random access.

* Associative containers:
    Stores elements in a sorted order based on a key, allowing for efficient search and retrieval.
    std::set        -   Stores unique elements in a sorted order.
    std::multiset   -   Stores elements in a sorted order, allowing for duplicate elements.
    std::map        -   Stores key-value pairs, where keys are unique and sorted.
    std::multimap   -   Stores key-value pairs, allowing for duplicate keys and sorted by key.

*   Container adaptors:
    These provides a different interface to underlying sequential containers, restricting or modifying their functionality for specific purposes.
    std::stack      - A LIFO (last in first out) data structure, implemented using std::deque or std::list as its underlying container
                LIFO: [a][b][c][d][e(top)] <->push/pop
    std::queue      - A FIFO (first in first out) data structure, implemented using std::deque or std::list as its underlying container
                FIFO: enqueue-> [(rear)a][b][c][d][e(front)] ->dequeue
    std::priority_queue: A queue where elements are retrieved based on their priority, implemented using std::vector as its underlying container.
*/

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>

int main()
{
    std::cout << "testing non-const" << std::endl;
    {
        std::cout << "vector test" << std::endl;
        std::vector<int> v;
        for (int i = 0; i < 5; i++)
            v.push_back(i + 5);

        for (int x = 0; x < 10; x++)
        {
            std::vector<int>::iterator v_i = easyfind(v, x);
            if (v_i != v.end())
                std::cout << "integer " << x << " found at index " << std::distance(v.begin(), v_i) << " => "
                          << "v[std::distance(v.begin(), v_i)] => " << v[std::distance(v.begin(), v_i)] << std::endl;
            else
                std::cout << "integer " << x << " not found." << std::endl;
        }
    }
    {
        std::cout << "list test" << std::endl;
        std::list<int> l;
        for (int i = 0; i < 5; i++)
            l.push_back(i + 5);

        for (int x = 0; x < 10; x++)
        {
            std::list<int>::iterator l_i = easyfind(l, x);
            if (l_i != l.end())
                std::cout << "integer " << x << " found at index " << std::distance(l.begin(), l_i) << " => "
                          << "*l_i => " << *l_i << std::endl;
            else
                std::cout << "integer " << x << " not found." << std::endl;
        }
    }
    {
        std::cout << "deque test" << std::endl;
        std::deque<int> d;
        for (int i = 0; i < 5; i++)
            d.push_back(i + 5);

        for (int x = 0; x < 10; x++)
        {
            std::deque<int>::iterator d_i = easyfind(d, x);
            if (d_i != d.end())
                std::cout << "integer " << x << " found at index " << std::distance(d.begin(), d_i) << " => "
                          << "*d_i => " << *d_i << std::endl;
            else
                std::cout << "integer " << x << " not found." << std::endl;
        }
    }

    std::cout << "testing const" << std::endl;
    {
        std::cout << "const vector test" << std::endl;
        std::vector<int> tmp_v;
        for (int i = 0; i < 5; ++i)
            tmp_v.push_back(i + 5);
        const std::vector<int> cv(tmp_v.begin(), tmp_v.end());

        for (int x = 0; x < 10; ++x)
        {
            std::vector<int>::const_iterator it = easyfind(cv, x);
            if (it != cv.end())
                std::cout << "integer " << x << " found at index " << std::distance(cv.begin(), it)
                          << " => *it => " << *it << std::endl;
            else
                std::cout << "integer " << x << " not found." << std::endl;
        }
    }

    {
        std::cout << "const list test" << std::endl;
        std::list<int> tmp_l;
        for (int i = 0; i < 5; ++i)
            tmp_l.push_back(i + 5);
        const std::list<int> cl(tmp_l.begin(), tmp_l.end());

        for (int x = 0; x < 10; ++x)
        {
            std::list<int>::const_iterator it = easyfind(cl, x);
            if (it != cl.end())
                std::cout << "integer " << x << " found at index " << std::distance(cl.begin(), it)
                          << " => *it => " << *it << std::endl;
            else
                std::cout << "integer " << x << " not found." << std::endl;
        }
    }

    {
        std::cout << "const deque test" << std::endl;
        std::deque<int> tmp_d;
        for (int i = 0; i < 5; ++i)
            tmp_d.push_back(i + 5);
        const std::deque<int> cd(tmp_d.begin(), tmp_d.end());

        for (int x = 0; x < 10; ++x)
        {
            std::deque<int>::const_iterator it = easyfind(cd, x);
            if (it != cd.end())
                std::cout << "integer " << x << " found at index " << std::distance(cd.begin(), it)
                          << " => *it => " << *it << std::endl;
            else
                std::cout << "integer " << x << " not found." << std::endl;
        }
    }

    std::cout << "testing empty" << std::endl;
    {
        std::cout << "empty vector test" << std::endl;
        std::vector<int> ev;
        std::vector<int>::iterator itv = easyfind(ev, 0);
        if (itv == ev.end())
            std::cout << "value not found" << std::endl;
        else
            std::cout << "WTF value found" << std::endl;
    }
    {
        std::cout << "empty list test" << std::endl;
        std::list<int> el;
        std::list<int>::iterator itl = easyfind(el, 0);
        if (itl == el.end())
            std::cout << "value not found" << std::endl;
        else
            std::cout << "WTF value found" << std::endl;
    }
    {
        std::cout << "empty deque test" << std::endl;
        std::deque<int> ed;
        std::deque<int>::iterator itd = easyfind(ed, 0);
        if (itd == ed.end())
            std::cout << "value not found" << std::endl;
        else
            std::cout << "WTF value found" << std::endl;
    }
}
