#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// Reference: https://en.cppreference.com/w/cpp/container/map

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


class BitcoinExchange {
public:
    // Orthodox Canonical Form
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    // member functions
    bool loadDatabase(const std::string& filename); 
    void processInput(const std::string& filename);


private:
    std::map<std::string, float> database;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const float value) const;
    std::string findClosestLowerDate(const std::string& date) const;
    int extractAndConvert(const std::string& str) const;

};

#endif