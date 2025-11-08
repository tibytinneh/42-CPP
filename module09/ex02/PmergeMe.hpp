#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
private:
    PmergeMe(const PmergeMe &o);
    PmergeMe &operator=(const PmergeMe &o);

public:
    PmergeMe();
    ~PmergeMe();

    void buildContainers(int ac, char **av);
    void swap_pairs(); // wrapper for swap_pairs_level(0)

public:
    const std::vector<unsigned int> &getVector() const;
    const std::deque<unsigned int> &getDeque() const;
    int size() const;
    void printVector(const std::string &s, const std::vector<unsigned int> &v) const;
    void printDeque(const std::string &s, const std::deque<unsigned int> &d) const;

private: // for buildContainers
    bool isAllDigits(const std::string &s);
    bool parseUInt(const std::string &s, unsigned int &out);
    void checkDuplicates(const std::vector<unsigned int> &v);

private:                                                 // for swap_pairs
    void swap_pairs_level_vector(int level, bool trace); // recursive
    void swap_pairs_level_deque(int level, bool trace);  // recursive

private:
    std::vector<unsigned int> _v; // filled vector from input
    std::deque<unsigned int> _d;  // filled deque from input
    int _n;                       // total number of elements
};