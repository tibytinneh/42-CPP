#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
public:
    /* OCF */
    BitcoinExchange(const std::string &path); // constructor => load database from data.csv
    BitcoinExchange(const BitcoinExchange &o);
    BitcoinExchange &operator=(const BitcoinExchange &o);
    ~BitcoinExchange();

    // process input file.
    void processFile(const std::string &path) const; // process file lines "YYYY-MM-DD | value" => prints results

private:
    /* STL STD::MAP TO CONTAIN RATES*/
    std::map<std::string, float> _rates; // date (YYYY-MM-DD) -> price
    void loadDb(const std::string &path);

    // return a const iterator pointing to the valid rate on same day / closest lower rate
    std::map<std::string, float>::const_iterator findValidRate(const std::string &date) const; // lookup

    // parsing & validation
    static std::string trim(const std::string &s);
    static bool isLeapYear(int yyyy);
    static bool isValidDate(const std::string &s);
    static bool parsefloat(const std::string &s, float &o);
};