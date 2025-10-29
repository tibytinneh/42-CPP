#include "Span.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <ctime>

static void printSpan(const Span &s)
{
    std::cout << "size: " << s.size()
              << " shortestSpan: " << s.shortestSpan()
              << " longestSpan: " << s.longestSpan()
              << std::endl;
}

int main()
{
    // pdf
    std::cout << "\ntest: pdf" << std::endl;
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "\ntest: exception" << std::endl;
        try
        {
            Span sp(3);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
        }
        catch (const std::exception &e)
        {
            std::cout << "Capacity overflow: " << e.what() << std::endl;
        }
        try
        {
            Span sp(2);
            sp.addNumber(6);
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Not enough numbers to calculate span: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\ntest: 10k range + fill span using range of iterators addRange()" << std::endl;

        Span tenk(10000);

        std::vector<int> v;
        v.reserve(10000);
        for (unsigned int i = 0; i < 10000; i++)
            v.push_back(static_cast<int>(i * 2));

        std::vector<int> sv = v;
        // shuffle
        std::random_shuffle(sv.begin(), sv.end());

        tenk.addRange(sv.begin(), sv.end());

        printSpan(tenk);
    }

    {
        std::cout << "\ntest: duplicat test so that shortestSpan is 0" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(6);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        printSpan(sp);
    }

    {
        std::cout << "\ntest: range insert from vector/list/deque" << std::endl;
        Span sp(6);

        std::vector<int> v;
        v.push_back(1);
        v.push_back(3);
        sp.addRange(v.begin(), v.end());

        std::list<int> l;
        l.push_back(5);
        l.push_back(7);
        sp.addRange(l.begin(), l.end());

        std::deque<int> d;
        d.push_back(9);
        d.push_back(99);
        sp.addRange(d.begin(), d.end());

        printSpan(sp);
    }

    {
        std::cout << "\ntest: exception test overflow range insert from vector. " << std::endl;
        Span sp(3);

        std::vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(7);
        v.push_back(13);

        try
        {
            sp.addRange(v.begin(), v.end());
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        printSpan(sp);
    }

    return 0;
}