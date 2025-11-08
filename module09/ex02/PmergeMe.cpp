#include "PmergeMe.hpp"

#include <stdexcept> //stderror
#include <set>       //std::set for duplicate
#include <cctype>    //std::isdigit
#include <cstdlib>   //std::strtoul
#include <cerrno>    //errno, ERANGE
#include <climits>   // UINT_MAX
#include <iostream>
#include <algorithm> // std::swap

PmergeMe::PmergeMe() : _v(), _d(), _n(0) {}
PmergeMe::PmergeMe(const PmergeMe &o) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &o) {}
PmergeMe::~PmergeMe() {}

void PmergeMe::buildContainers(int ac, char **av)
{

    std::vector<unsigned int> tmp;
    tmp.reserve(ac - 1);

    for (int i = 1; i < ac; i++)
    {
        if (!av[i] || !*av[i])
            throw std::runtime_error("Empty argument.");
        std::string token = av[i];
        unsigned int value = 0;
        if (!(parseUInt(token, value)))
        {
            throw std::runtime_error("Invalid token. (non digit, zero, negative or overflow)");
        }
        tmp.push_back(value);
    }
    checkDuplicates(tmp);

    _v.swap(tmp);
    _d.assign(_v.begin(), _v.end());
    _n = static_cast<int>(_v.size());
}

const std::vector<unsigned int> &PmergeMe::getVector() const { return _v; }
const std::deque<unsigned int> &PmergeMe::getDeque() const { return _d; }
int PmergeMe::size() const { return _n; }
void PmergeMe::printVector(const std::string &s, const std::vector<unsigned int> &v) const
{
    std::cout << s;
    if (!v.empty() && !s.empty() && s[s.size() - 1] != ' ')
        std::cout << ' ';

    for (std::vector<unsigned int>::size_type i = 0; i < v.size(); ++i)
    {
        std::cout << v[i];
        if (i + 1 < v.size())
            std::cout << ' ';
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(const std::string &s, const std::deque<unsigned int> &d) const
{
    std::cout << s;
    if (!d.empty() && !s.empty() && s[s.size() - 1] != ' ')
        std::cout << ' ';

    for (std::deque<unsigned int>::size_type i = 0; i < d.size(); ++i)
    {
        std::cout << d[i];
        if (i + 1 < d.size())
            std::cout << ' ';
    }
    std::cout << std::endl;
}

bool PmergeMe::parseUInt(const std::string &s, unsigned int &out)
{
    if (!isAllDigits(s))
        return false;
    errno = 0;
    unsigned long tmp = std::strtoul(s.c_str(), NULL, 10);

    if (errno == ERANGE) // overflow
        return false;
    if (tmp == 0ul) // pdf: cannot be zero
        return false;
    if (tmp > static_cast<unsigned long>(UINT_MAX))
        return false;
    out = static_cast<unsigned int>(tmp);
    return true;
}

bool PmergeMe::isAllDigits(const std::string &s)
{
    if (s.empty())
        return false;
    for (std::string::size_type i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

void PmergeMe::checkDuplicates(const std::vector<unsigned int> &v)
{
    std::set<unsigned int> se(v.begin(), v.end());
    if (se.size() != v.size())
    {
        throw std::runtime_error("Duplicate found.");
    }
}

void PmergeMe::swap_pairs()
{
    swap_pairs_level_vector(0, /*trace*/ true);
    swap_pairs_level_deque(0, /*trace*/ true);
}

void PmergeMe::swap_pairs_level_vector(int level, bool trace)
{
    const std::size_t num_of_ele = _v.size();

    std::size_t group_size = static_cast<std::size_t>(1) << level; // 1u << level computes 2^level
    std::size_t pair_size = group_size << 1;                       // << 1 computes 2 * group_size

    if (pair_size > num_of_ele)
        return; // base case

    std::size_t num_pairs = num_of_ele / pair_size;

    for (std::size_t p = 0; p < num_pairs; p++)
    {
        // base index of pair block
        std::size_t base = p * pair_size;

        std::size_t left_last = base + (group_size - 1);
        std::size_t right_last = base + (pair_size - 1);

        if (_v[left_last] > _v[right_last])
        {
            for (std::size_t t = 0; t < group_size; t++)
            {
                std::swap(_v[base + t], _v[base + group_size + t]);
            }
        }
        if (trace)
        {
            std::cout << "\033[34mL" << level << ": \033[0m";
            for (std::size_t i = 0; i < num_of_ele; ++i)
            {
                std::cout << _v[i] << (i + 1 < num_of_ele ? ' ' : '\n');
            }
        }
    }
    swap_pairs_level_vector(level + 1, trace);
}

void PmergeMe::swap_pairs_level_deque(int level, bool trace)
{
    const std::size_t num_of_ele = _d.size();

    std::size_t group_size = std::size_t(1) << level; // 2^level
    std::size_t pair_size = group_size << 1;          // 2*group_size

    if (pair_size > num_of_ele)
        return; // base case

    std::size_t num_pairs = num_of_ele / pair_size;

    for (std::size_t p = 0; p < num_pairs; ++p)
    {
        std::size_t base = p * pair_size;
        std::size_t left_last = base + (group_size - 1);
        std::size_t right_last = base + (pair_size - 1);

        if (_d[left_last] > _d[right_last])
        {
            for (std::size_t t = 0; t < group_size; ++t)
                std::swap(_d[base + t], _d[base + group_size + t]);
        }

        if (trace)
        {
            std::cout << "\033[35mL" << level << ": \033[0m";
            for (std::size_t i = 0; i < num_of_ele; ++i)
                std::cout << _d[i] << (i + 1 < num_of_ele ? ' ' : '\n');
        }
    }

    swap_pairs_level_deque(level + 1, trace);
}
