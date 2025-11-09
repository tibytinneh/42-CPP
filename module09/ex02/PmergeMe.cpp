#include "PmergeMe.hpp"

#include <stdexcept> //stderror
#include <set>       //std::set for duplicate
#include <cctype>    //std::isdigit
#include <cstdlib>   //std::strtoul
#include <cerrno>    //errno, ERANGE
#include <climits>   // UINT_MAX
#include <iostream>
#include <algorithm> // std::swap
static inline unsigned int last_ofV(const std::vector<unsigned int> &v)
{
    return v.empty() ? 0 : v[v.size() - 1];
}

static inline unsigned int last_ofD(const std::deque<unsigned int> &d)
{
    return d.empty() ? 0 : d[d.size() - 1];
}
PmergeMe::PmergeMe() : _v(), _d(), _n(0) {}
PmergeMe::PmergeMe(const PmergeMe &o) { (void)o; }
PmergeMe &PmergeMe::operator=(const PmergeMe &o)
{
    (void)o;
    return *this;
}
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
void PmergeMe::sort_vector(bool trace)
{
    swap_pairs_level_vector(0, /*trace*/ true);
    int top = highestlevelVector();
    for (int level = top; level >= 0; --level)
    {
        std::vector<GroupV> mainV, pEndV;
        std::vector<unsigned int> remV;

        build_level_groups_vector(level, mainV, pEndV, remV);
        sort_chain_by_insertion_v(mainV);
        if (trace)
        {
            std::cout << "\n\033[34m[sort_vector] Level: \033[0m" << level << "\n";
            printGroupV("main (v): ", mainV);
            printGroupV("pEnd (v): ", pEndV);
            std::cout << "\033[34mremainder: ";
            if (remV.empty())
                std::cout << "(N.A)\n";
            else
                for (std::size_t i = 0; i < remV.size(); i++)
                    std::cout << remV[i] << " ";
            std::cout << "STEP 3: BINARY INSERTION\n";
        }

        insert_pend_v(mainV, pEndV, trace);
        if (trace)
            std::cout << "Join remainder back to main \n";
        stitch_v(mainV, remV);
    }
}

void PmergeMe::sort_deque(bool trace)
{
    swap_pairs_level_deque(0, /*trace*/ true);
    int top = highestlevelDeque();
    for (int level = top; level >= 0; --level)
    {
        std::deque<GroupD> mainD, pEndD;
        std::deque<unsigned int> remD;

        build_level_groups_deque(level, mainD, pEndD, remD);
        sort_chain_by_insertion_d(mainD);
        if (trace)
        {
            std::cout << "\n\033[35m[sort_deque] Level: \033[0m" << level << "\n";
            printGroupD("main (d): ", mainD);
            printGroupD("pEnd (d): ", pEndD);
            std::cout << "\033[35mremainder: ";
            if (remD.empty())
                std::cout << "(N.A)\n";
            else
                for (std::size_t i = 0; i < remD.size(); i++)
                    std::cout << remD[i] << " ";
        }
        std::cout << "STEP 3: BINARY INSERTION\n";

        insert_pend_d(mainD, pEndD, trace);
        if (trace)
            std::cout << "Join remainder back to main \n";
        stitch_d(mainD, remD);
    }
}

int PmergeMe::highestlevelVector() const
{
    std::size_t n = _v.size();
    if (n < 2)
        return -1;

    std::size_t pair_size = 2; // level 0
    int level = 0;

    while (pair_size <= n)
    {
        ++level;
        pair_size <<= 1; // next level doubles the pair size
    }

    return level - 1; // last valid level
}

int PmergeMe::highestlevelDeque() const
{
    std::size_t n = _d.size();
    if (n < 2)
        return -1;

    std::size_t pair_size = 2; // level 0
    int level = 0;

    while (pair_size <= n)
    {
        ++level;
        pair_size <<= 1; // next level doubles the pair size
    }

    return level - 1; // last valid level
}

void PmergeMe::printGroupV(const char *s, const std::vector<GroupV> &gv)
{
    std::cout << "\033[34m" << s << std::endl;
    for (std::size_t i = 0; i < gv.size(); i++)
    {
        std::cout << (gv[i].kind == 'B' ? 'B' : 'A') << gv[i].pair_idx << "[";
        for (std::size_t j = 0; j < gv[i].v.size(); j++)
        {
            std::cout << gv[i].v[j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << " \n\033[0m";
}

void PmergeMe::printGroupD(const char *s, const std::deque<GroupD> &gd)
{
    std::cout << "\033[35m" << s << std::endl;
    for (std::size_t i = 0; i < gd.size(); i++)
    {
        std::cout << (gd[i].kind == 'B' ? 'B' : 'A') << gd[i].pair_idx << "[";
        for (std::size_t j = 0; j < gd[i].d.size(); j++)
        {
            std::cout << gd[i].d[j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << " \n\033[0m";
}

// Build group for a single level from _v or _d
void PmergeMe::build_level_groups_vector(
    int level,
    std::vector<GroupV> &mainV,
    std::vector<GroupV> &pendV,
    std::vector<unsigned int> &remV) const
{
    mainV.clear();
    pendV.clear();
    remV.clear();

    const std::size_t n = _v.size();

    const std::size_t group_size = std::size_t(1) << level; // pow2
    const std::size_t pair_size = group_size << 1;          // multi2

    if (pair_size == 0 || pair_size > n)
        return; // base case

    std::size_t num_of_pairs = n / pair_size;

    for (std::size_t p = 0; p < num_of_pairs; ++p)
    {
        std::size_t base = p * pair_size;
        GroupV left;
        left.kind = 'B';
        left.pair_idx = p + 1;
        GroupV right;
        right.kind = 'A';
        right.pair_idx = p + 1;
        left.v.resize(group_size); // prep for indexed assignments
        right.v.resize(group_size);
        for (std::size_t t = 0; t < group_size; t++)
        {
            left.v[t] = _v[base + t];
            right.v[t] = _v[base + group_size + t];
        }
        if (p == 0)
            mainV.push_back(left); // b1
        else
            pendV.push_back(left); // b2...b?
        mainV.push_back(right);    // all a?

    } // END with: main: b1 + a...a?
      //           pEnd: b2 ..... b?

    std::size_t stored = num_of_pairs * pair_size;
    for (std::size_t i = stored; i < n; ++i)
        remV.push_back(_v[i]); // fill up remainder.
}

void PmergeMe::build_level_groups_deque(
    int level,
    std::deque<GroupD> &mainD,
    std::deque<GroupD> &pendD,
    std::deque<unsigned int> &remD) const
{
    mainD.clear();
    pendD.clear();
    remD.clear();

    const std::size_t n = _d.size();

    const std::size_t group_size = std::size_t(1) << level; // pow2
    const std::size_t pair_size = group_size << 1;          // multi2

    if (pair_size == 0 || pair_size > n)
        return; // base case

    std::size_t num_of_pairs = n / pair_size;

    for (std::size_t p = 0; p < num_of_pairs; ++p)
    {
        std::size_t base = p * pair_size;
        GroupD left;
        left.kind = 'B';
        left.pair_idx = p + 1;
        GroupD right;
        right.kind = 'A';
        right.pair_idx = p + 1;
        left.d.resize(group_size); // prep for indexed assignments
        right.d.resize(group_size);
        for (std::size_t t = 0; t < group_size; t++)
        {
            left.d[t] = _d[base + t];
            right.d[t] = _d[base + group_size + t];
        }
        if (p == 0)
            mainD.push_back(left); // b1
        else
            pendD.push_back(left); // b2...b?
        mainD.push_back(right);    // all a?

    } // END with: main: b1 + a...a?
      //           pEnd: b2 ..... b?

    std::size_t stored = num_of_pairs * pair_size;
    for (std::size_t i = stored; i < n; ++i)
        remD.push_back(_d[i]); // fill up remainder.
}

void PmergeMe::insert_pend_v(std::vector<GroupV> &mainV, std::vector<GroupV> &pEndV, bool trace)
{
    const std::size_t pend = pEndV.size();
    const std::size_t m_b = 1 + pend; // b1...  b_m_b

    std::vector<std::size_t> order;
    jacobsthal_b_order_v(m_b, order);

    for (std::size_t o = 0; o < order.size(); o++)
    {
        std::size_t j = order[o];
        std::size_t pair_idx = (j >= 2) ? (j - 2) : 0; // start from b2 -> [0], b3 -> [1]
        if (pair_idx >= pend)
            continue;
        const GroupV &bj = pEndV[pair_idx]; // copy for inserting

        // find position of 'A'j
        std::size_t posAj = 0;
        bool found = false;

        for (std::size_t i = 0; i < mainV.size(); i++)
        {
            if (mainV[i].kind == 'A' && mainV[i].pair_idx == j)
            {
                posAj = i;
                found = true;
                break;
            }
        }
        std::size_t L = 0, R = mainV.size();
        if (found)
        {
            const unsigned int keyBj = last_ofV(bj.v);
            const unsigned int keyAj = last_ofV(mainV[posAj].v);
            if (keyBj <= keyAj)
                R = posAj; // insert before Aj
            else
                L = posAj + 1; // insert after Aj
        }

        const std::size_t ins = lowerBoundV(mainV, bj, L, R);
        mainV.insert(mainV.begin() + static_cast<std::ptrdiff_t>(ins), bj);
        if (trace)
        {
            std::cout << "\033[34mInsert B" << j << " in " << L << ", " << R << " pos" << ins << "\n";
            printGroupV("Main:", mainV);
            std::cout << "\033[0m";
        }
    }
}

void PmergeMe::insert_pend_d(std::deque<GroupD> &mainD, std::deque<GroupD> &pEndD, bool trace)
{
    const std::size_t pend = pEndD.size();
    const std::size_t m_b = 1 + pend; // b1...  b_m_b

    std::deque<std::size_t> order;
    jacobsthal_b_order_d(m_b, order);

    for (std::size_t o = 0; o < order.size(); o++)
    {
        std::size_t j = order[o];
        std::size_t pair_idx = (j >= 2) ? (j - 2) : 0; // start from b2 -> [0], b3 -> [1]
        if (pair_idx >= pend)
            continue;
        const GroupD &bj = pEndD[pair_idx]; // copy for inserting

        // find position of 'A'j
        std::size_t posAj = 0;
        bool found = false;

        for (std::size_t i = 0; i < mainD.size(); i++)
        {
            if (mainD[i].kind == 'A' && mainD[i].pair_idx == j)
            {
                posAj = i;
                found = true;
                break;
            }
        }
        std::size_t L = 0, R = mainD.size();
        if (found)
        {
            const unsigned int keyBj = last_ofD(bj.d);
            const unsigned int keyAj = last_ofD(mainD[posAj].d);
            if (keyBj <= keyAj)
                R = posAj;
            else
                L = posAj + 1;
        }

        const std::size_t ins = lowerBoundD(mainD, bj, L, R);
        mainD.insert(mainD.begin() + static_cast<std::ptrdiff_t>(ins), bj);
        if (trace)
        {
            std::cout << "\033[34mInsert B" << j << " in " << L << ", " << R << " pos" << ins << "\n";
            printGroupD("Main:", mainD);
            std::cout << "\033[0m";
        }
    }
}

std::size_t PmergeMe::lowerBoundV(
    const std::vector<GroupV> &mainV, const GroupV &bj, std::size_t L, std::size_t R)
{
    unsigned int key = last_ofV(bj.v);
    while (L < R)
    {
        std::size_t mid = L + (R - L) / 2;
        if (last_ofV(mainV[mid].v) < key)
            L = mid + 1;
        else
            R = mid;
    }
    return L;
}

std::size_t PmergeMe::lowerBoundD(
    const std::deque<GroupD> &mainD, const GroupD &bj, std::size_t L, std::size_t R)
{
    unsigned int key = last_ofD(bj.d);
    while (L < R)
    {
        std::size_t mid = L + (R - L) / 2;
        if (last_ofD(mainD[mid].d) < key)
            L = mid + 1;
        else
            R = mid;
    }
    return L;
}

// Keep using your existing lowerBoundV/D (they compare by last element).
void PmergeMe::sort_chain_by_insertion_v(std::vector<GroupV> &mainV)
{
    std::vector<GroupV> sorted;
    sorted.reserve(mainV.size());
    for (std::size_t i = 0; i < mainV.size(); ++i)
    {
        const std::size_t ins = lowerBoundV(sorted, mainV[i], 0, sorted.size());
        sorted.insert(sorted.begin() + static_cast<std::ptrdiff_t>(ins), mainV[i]);
    }
    mainV.swap(sorted);
}

void PmergeMe::sort_chain_by_insertion_d(std::deque<GroupD> &mainD)
{
    std::deque<GroupD> sorted;
    for (std::size_t i = 0; i < mainD.size(); ++i)
    {
        const std::size_t ins = lowerBoundD(sorted, mainD[i], 0, sorted.size());
        sorted.insert(sorted.begin() + static_cast<std::ptrdiff_t>(ins), mainD[i]);
    }
    mainD.swap(sorted);
}

void PmergeMe::jacobsthal_b_order_v(std::size_t m_b, std::vector<std::size_t> &order)
{
    order.clear();
    if (m_b <= 1)
        return;
    std::size_t prev = 1;
    std::size_t cur = 3;

    while (true)
    {
        if (cur <= m_b)
        {
            for (std::size_t i = cur; i > prev; i--)
            {
                if (i >= 2)
                    order.push_back(i);
            }
            // go next
            std::size_t nxt = cur + 2 * prev;
            prev = cur;
            cur = nxt;
        }
        else
        {
            for (std::size_t i = m_b; i > prev; i--)
            {
                if (i >= 2)
                    order.push_back(i);
            }
            break;
        }
    }
}

void PmergeMe::jacobsthal_b_order_d(std::size_t m_b, std::deque<std::size_t> &order)
{
    order.clear();
    if (m_b <= 1)
        return;
    std::size_t prev = 1;
    std::size_t cur = 3;

    while (true)
    {
        if (cur <= m_b)
        {
            for (std::size_t i = cur; i > prev; i--)
            {
                if (i >= 2)
                    order.push_back(i);
            }
            // go next
            std::size_t nxt = cur + 2 * prev;
            prev = cur;
            cur = nxt;
        }
        else
        {
            for (std::size_t i = m_b; i > prev; i--)
            {
                if (i >= 2)
                    order.push_back(i);
            }
            break;
        }
    }
}

void PmergeMe::stitch_v(const std::vector<GroupV> &mainV, const std::vector<unsigned int> &remV)
{
    std::vector<unsigned int> out;
    for (std::size_t i = 0; i < mainV.size(); i++)
    {
        out.insert(out.end(), mainV[i].v.begin(), mainV[i].v.end());
    }
    // insert remaining values into sorted vector using binary insert.
    for (std::size_t i = 0; i < remV.size(); i++)
    {
        std::vector<unsigned int>::iterator it = std::lower_bound(out.begin(), out.end(), remV[i]);
        out.insert(it, remV[i]);
    }

    _v.swap(out);
}

void PmergeMe::stitch_d(const std::deque<GroupD> &mainD, const std::deque<unsigned int> &remD)
{
    std::deque<unsigned int> out;
    for (std::size_t i = 0; i < mainD.size(); i++)
    {
        out.insert(out.end(), mainD[i].d.begin(), mainD[i].d.end());
    }
    // Insert remaining values into sorted deque using binary insert
    for (std::size_t i = 0; i < remD.size(); i++)
    {
        std::deque<unsigned int>::iterator it = std::lower_bound(out.begin(), out.end(), remD[i]);
        out.insert(it, remD[i]);
    }
    _d.swap(out);
}
