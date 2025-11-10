#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

// (ifstream&).seekg(0, std::ios:beg)
// moves the read cursor to the beginning of the file
// if first line has no header => rewind to beginning of file

/* OCF */

BitcoinExchange::BitcoinExchange(const std::string &path)
{
    loadDb(path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &o) : _rates(o._rates) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &o)
{
    if (this != &o)
        _rates = o._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/**
 * Load database file of historical rates.
 * Reads CSV lines of the form "YYYY-MM-DD,<rate>" (header optional),
 * validates and stores rates in the internal ordered map _rates.
 *
 * Invalid lines are skipped silently; file I/O errors are reported to stderr.
 *
 * @param {const std::string&} path - path to CSV database
 */
void BitcoinExchange::loadDb(const std::string &path)
{
    std::ifstream db(path.c_str());
    if (!db)
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    std::string line;
    if (std::getline(db, line))
    {
        // if header is not present:
        if (line.compare(0, 5, "date,") != 0)
        {
            // rewind back to start of file
            db.clear();
            db.seekg(0, std::ios::beg);
        }
        // else if header is present:
        // leave the cursor at the start of second line.
    }

    while (std::getline(db, line))
    {
        if (line.empty())
            continue;

        std::string::size_type comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, comma));
        std::string s_rate = trim(line.substr(comma + 1));

        if (!isValidDate(date))
            continue;
        float rate;
        if (!parsefloat(s_rate, rate))
            continue;
        // add date => rate into std::map _rates
        _rates[date] = rate;
    }
}

/**
 * Trim whitespace from both ends of a string.
 *
 * @param {const std::string&} s - input string
 * @return {std::string} trimmed copy (empty if s contained only whitespace)
 */
std::string BitcoinExchange::trim(const std::string &s)
{
    std::string::size_type i = 0;
    std::string::size_type j = s.size();

    while (i < j && std::isspace(static_cast<unsigned char>(s[i])))
        i++;
    while (j > i && std::isspace(static_cast<unsigned char>(s[j - 1])))
        j--;
    return s.substr(i, j - i);
}

/**
 * Validate date string in ISO format "YYYY-MM-DD".
 * Checks format, digits and valid month/day including leap-year rules.
 *
 * @param {const std::string&} s - date string to validate
 * @return {bool} true if s is a valid date in the supported range/format
 */
bool BitcoinExchange::isValidDate(const std::string &s)
{
    int yyyy;
    int mm;
    int dd;

    // YYYY-MM-DD format check
    if (s.size() != 10 || s[4] != '-' || s[7] != '-')
        return false;

    // YYYYMMMDD digit check
    for (size_t i = 0; i < s.size(); i++)
    {
        // skip '-'
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }

    yyyy = std::atoi(s.substr(0, 4).c_str());
    mm = std::atoi(s.substr(5, 2).c_str());
    dd = std::atoi(s.substr(8, 2).c_str());

    // MM validity check
    if (mm < 1 || mm > 12)
        return false;

    // set days of month + leap year check
    int mm_dd[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(yyyy))
        mm_dd[1] = 29;

    // DD validty check
    if (dd < 1 || dd > mm_dd[mm - 1])
        return false;

    return true;
}

/**
 * Test whether a year is a leap year.
 *
 * @param {int} yyyy - year
 * @return {bool} true if yyyy is a leap year
 */
bool BitcoinExchange::isLeapYear(int yyyy)
{
    // divisible by 400
    // divisible by 4 but not 100
    return (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0));
}

/**
 * Parse a floating-point number from a string strictly.
 * Uses an istringstream to detect trailing junk and invalid input.
 *
 * @param {const std::string&} s - input string to parse
 * @param {float&} o - output parsed value on success
 * @return {bool} true on successful parse (no trailing characters), false otherwise
 */
bool BitcoinExchange::parsefloat(const std::string &s, float &o)
{
    // check for junk using istringstream
    std::istringstream iss(s);
    iss >> o;
    if (!iss || !iss.eof())
        return false;
    return true;
}

/**
 * Find the applicable rate for a given date string.
 * Finds an exact match or the most recent date earlier than the requested date.
 *
 * If the requested date is earlier than any available rate, returns _rates.end().
 * If the requested date is later than all entries, returns iterator to the last element.
 *
 * @param {const std::string&} date - "YYYY-MM-DD" date to query
 * @return {std::map<std::string,float>::const_iterator} iterator to matching or closest prior rate, or _rates.end()
 */
std::map<std::string, float>::const_iterator BitcoinExchange::findValidRate(const std::string &date) const
{
    // binary search on the ordered map (O(log n))
    //  _rates.lower_bound(dates)
    // finds the first element whose key is not less than date

    std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
    // returns _rate.end()  =>  if requested date is > than all of map's keys
    //                      =>  or if map is empty.
    if (it == _rates.end())
    {
        if (_rates.empty())
            return _rates.end();

        std::map<std::string, float>::const_iterator last = _rates.end();
        last--;
        return last;
    }
    // if first object in iterator == date
    if (it->first == date)
        return it;
    // date earlier than all available keys
    if (it == _rates.begin())
        return _rates.end();
    it--;
    return it;
}

/**
 * Process an input file of "date | value" lines.
 * For each valid input line:
 *  - validates date and value
 *  - finds the applicable historical rate
 *  - computes value * rate and prints "date => value = result"
 *
 * Errors and malformed lines are reported to stdout with an explanatory message.
 *
 * @param {const std::string&} path - path to the input file to process
 */
void BitcoinExchange::processFile(const std::string &path) const
{
    /* date | value */
    std::ifstream in(path.c_str());
    if (!in)
    {
        std::cerr << "Error: could not open file.\n";
        return;
    }
    std::string tmp;
    std::string line;
    std::string date;
    std::string s_value;
    float value;
    while (std::getline(in, line))
    {
        if (line.empty())
            continue;
        tmp = line;

        std::string trimmed = trim(line);
        if (trimmed == "date | value")
            continue;

        std::string::size_type bar = line.find('|');
        if (bar == std::string::npos)
        {
            std::cerr << "Error: bad input => " << tmp << std::endl;
            continue;
        }
        date = trim(line.substr(0, bar));
        s_value = trim(line.substr(bar + 1));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << tmp << std::endl;
            continue;
        }
        if (!parsefloat(s_value, value))
        {
            std::cerr << "Error: bad input => " << tmp << std::endl;
            continue;
        }
        if (value < 0.0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000.0)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // find same day/ closest lower rate
        std::map<std::string, float>::const_iterator it = findValidRate(date);

        if (it == _rates.end())
        {
            std::cerr << "Error: bad input => " << tmp << std::endl;
            continue;
        }

        // value * rate on that day
        float result = value * it->second;
        std::cout << date << " => " << s_value << " = " << result << std::endl;
    }
}