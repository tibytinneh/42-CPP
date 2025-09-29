#pragma once

#include <cstddef>

template <typename T, typename F>
void iter(T *array, std::size_t n, F func)
{
    if (!array)
        return;
    for (std::size_t i = 0; i < n; i++)
        func(array[i]);
}

// SUPPORT CONST ARRAY
template <typename T, typename F>
void iter(T const *array, std::size_t n, F func)
{
    if (!array)
        return;
    for (std::size_t i = 0; i < n; i++)
        func(array[i]);
}