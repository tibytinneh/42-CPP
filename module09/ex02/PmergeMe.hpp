#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
private:
    PmergeMe(const PmergeMe &o);
    PmergeMe &operator=(const PmergeMe &o);
    struct GroupV
    {
        std::vector<unsigned int> v;
        char kind;
        std::size_t pair_idx;
    };
    struct GroupD
    {
        std::deque<unsigned int> d;
        char kind;
        std::size_t pair_idx;
    };

public:
    PmergeMe();
    ~PmergeMe();

    void buildContainers(int ac, char **av);
    void swap_pairs(); // wrapper for swap_pairs_level(0)
    void sort_vector(bool trace);
    void sort_deque(bool trace);

private:                                                 // for swap_pairs
    void swap_pairs_level_vector(int level, bool trace); // recursive
    void swap_pairs_level_deque(int level, bool trace);  // recursive

public: // helpers
    const std::vector<unsigned int> &getVector() const;
    const std::deque<unsigned int> &getDeque() const;
    int size() const;
    void printVector(const std::string &s, const std::vector<unsigned int> &v) const;
    void printDeque(const std::string &s, const std::deque<unsigned int> &d) const;
    void printGroupV(const char *s, const std::vector<GroupV> &gv);
    void printGroupD(const char *s, const std::deque<GroupD> &gd);
    int highestlevelVector() const;
    int highestlevelDeque() const;

    void build_level_groups_vector(
        int level,
        std::vector<GroupV> &mainV,
        std::vector<GroupV> &pendV,
        std::vector<unsigned int> &remV) const;

    void build_level_groups_deque(
        int level,
        std::deque<GroupD> &mainD,
        std::deque<GroupD> &pendD,
        std::deque<unsigned int> &remD) const;

    void insert_pend_v(std::vector<GroupV> &mainV,
                       std::vector<GroupV> &pEndV,
                       bool trace);
    void insert_pend_d(std::deque<GroupD> &mainD,
                       std::deque<GroupD> &pEndD,
                       bool trace);
    void jacobsthal_b_order_v(std::size_t m_b, std::vector<std::size_t> &order);
    void jacobsthal_b_order_d(std::size_t m_b, std::deque<std::size_t> &order);

    std::size_t lowerBoundV(
        const std::vector<GroupV> &mainV, const GroupV &bj, std::size_t L, std::size_t R);

    std::size_t lowerBoundD(
        const std::deque<GroupD> &mainD, const GroupD &bj, std::size_t L, std::size_t R);
    void stitch_v(const std::vector<GroupV> &mainV, const std::vector<unsigned int> &remV);
    void stitch_d(const std::deque<GroupD> &mainD, const std::deque<unsigned int> &remD);
    void final_insert_v();
    void final_insert_d();

private: // for buildContainers
    bool isAllDigits(const std::string &s);
    bool parseUInt(const std::string &s, unsigned int &out);
    void checkDuplicates(const std::vector<unsigned int> &v);

private:
    std::vector<unsigned int> _v; // filled vector from input
    std::deque<unsigned int> _d;  // filled deque from input
    int _n;
    // total number of elements
};