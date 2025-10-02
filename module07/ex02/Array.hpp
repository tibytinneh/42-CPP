#pragma once

#include <stdexcept> //for throwing std::out_of_range
#include <ostream>

template <typename T>
class Array
{
private:
    T *_data;
    unsigned int _size;

public:
    // constructor with no parameter: creates an empty array
    Array() : _data(0), _size(0) {}

    // constructor with an unsgined int n as a parameter:
    // creates an array of n elements initialized by default ( use new <DATATYPE>() )
    // explicit to prevent accidental implicit conversion from unsigned int to array
    explicit Array(unsigned int n) : _data(0), _size(n)
    {
        if (_size)
        {
            _data = new T[_size]();
        }
    }

    // copy constructor
    // must be DEEP copy
    Array(const Array &o) : _data(0), _size(o._size)
    {
        if (_size)
        {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = o._data[i];
        }
    }
    Array &operator=(const Array &rhs)
    {
        if (this != &rhs)
        {
            T *newdata = 0;
            if (rhs._size)
            {
                newdata = new T[rhs._size];
                for (unsigned int i = 0; i < rhs._size; i++)
                    newdata[i] = rhs._data[i];
            }
            delete[] _data;    // delete old memory
            _data = newdata;   // commit new data
            _size = rhs._size; // commit new size
        }
        return *this;
    }
    ~Array() { delete[] _data; };

public:
    // subscript operator ([]) with bounds check
    T &operator[](unsigned int i)
    {
        if (i >= _size)
            throw std::out_of_range("Array: index out of range."); // throws std::exception
        return _data[i];                                           // return element if index is good
    }

    T const &operator[](unsigned int i) const
    {
        if (i >= _size)
            throw std::out_of_range("Array: index out of range.");
        return _data[i];
    }

public:
    unsigned int size() const { return _size; }
    void print() const
    {
        if (_size)
        {
            for (unsigned int i = 0; i < _size; i++)
                std::cout << _data[i];
        }
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &a)
{
    os << "size: " << a.size();
    os << " [";
    for (unsigned int i = 0; i < a.size(); i++)
    {
        os << a[i];
    }
    os << "]\n";
    return os;
}