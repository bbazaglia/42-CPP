#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    if (this != &other)
        *this = other;
};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        database = other.database;
    return *this;
};

BitcoinExchange::~BitcoinExchange() {};

int BitcoinExchange::extractAndConvert(const std::string& str) const {
    std::istringstream ss(str);
    int value;
    ss >> value;

    if (ss.fail()) {
        return -1;
    }

    return value;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = extractAndConvert(date.substr(0, 4));
    int month = extractAndConvert(date.substr(5, 2));
    int day = extractAndConvert(date.substr(8, 2));

    if (month < 1 || month > 12 || day < 1 || year < 0) 
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
};

bool BitcoinExchange::isValidValue(const float value) const
{
    return value >= 0 && value <= 1000;
};

std::string BitcoinExchange::findClosestLowerDate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);
    if (it == database.begin() && it->first != date)
        return "";
    if (it == database.end() || it->first != date)
    {
        if (it == database.begin())
            return "";
        --it;
    }
    return it->first;
};

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    // Skip header
    getline(file, line);

    while (getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = line.substr(0, comma);
        float price = atof(line.substr(comma + 1).c_str());

        if (isValidDate(date))
            database[date] = price;
    }
    file.close();
    return true;
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    // Skip header
    getline(file, line);

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        size_t separator = line.find(" | ");
        if (separator == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, separator);
        std::string valueStr = line.substr(separator + 3);

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        std::istringstream iss(valueStr);
        if (!(iss >> value) || !iss.eof())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidValue(value))
        {
            if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::string closestDate = findClosestLowerDate(date);
        if (closestDate.empty())
        {
            std::cout << "Error: no bitcoin price available for this date." << std::endl;
            continue;
        }

        float result = value * database[closestDate];
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}
