#include "Span.hpp"

/*  std::vector::reserve increases the capacity of the vector to at least the specified number of elements,
    if the currently capacity is less than the requested amount.
    Calling reserve() reduces the overhead of frequent memory allocations.
    no shrinking, reserve() will only increase not decrease.
        shrink_to_fit() can be used to shrink.
*/
Span::Span(unsigned int n) : _n(n), _data()
{
    _data.reserve(n);
}

Span::Span(const Span &o) : _n(o._n), _data(o._data) {}

Span &Span::operator=(const Span &o)
{
    if (this != &o)
    {
        _n = o._n;
        _data = o._data;
    }
    return *this;
}

Span::~Span() {}

unsigned int Span::getN() const { return _n; }
unsigned int Span::size() const { return static_cast<unsigned int>(_data.size()); }

void Span::addNumber(int val)
{
    if (size() >= _n)
        throw std::runtime_error("Span's capacity is full.");
    _data.push_back(val);
}

unsigned int Span::longestSpan() const
{
    if (size() < 2)
        throw std::runtime_error("Not enough numbers.");
    std::vector<int>::const_iterator min_ele = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator max_ele = std::max_element(_data.begin(), _data.end());
    long diff = static_cast<long>(*max_ele) - static_cast<long>(*min_ele);
    return static_cast<unsigned int>(diff);
}

unsigned int Span::shortestSpan() const
{
    if (size() < 2)
        throw std::runtime_error("Not enough numbers.");

    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());

    unsigned int smallest_diff = std::numeric_limits<unsigned int>::max();
    for (std::vector<int>::size_type i = 0; i + 1 < tmp.size(); i++)
    {
        long diff = static_cast<long>(tmp[i + 1]) - static_cast<long>(tmp[i]);
        if (static_cast<unsigned long>(diff) < smallest_diff)
            smallest_diff = static_cast<unsigned int>(diff);
        if (smallest_diff == 0u)
            break;
    }
    return smallest_diff;
}

Span::iterator Span::begin() { return _data.begin(); }
Span::iterator Span::end() { return _data.end(); }
Span::const_iterator Span::begin() const { return _data.begin(); }
Span::const_iterator Span::end() const { return _data.end(); }