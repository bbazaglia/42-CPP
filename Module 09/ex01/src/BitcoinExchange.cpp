#include "BitcoinExchange.hpp"
#include <cstdlib>

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
    ss >> value; // attempt to extract an integer from the string

    if (ss.fail()) {
        return -1;
    }

    return value;
}


bool BitcoinExchange::isValidDate(const std::string &date) const
{
    // check format YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    // extract year, month and day 
    int year = extractAndConvert(date.substr(0, 4));
    int month = extractAndConvert(date.substr(5, 2));
    int day = extractAndConvert(date.substr(8, 2));

    // check valid ranges
    if (month < 1 || month > 12 || day < 1 || year < 0) 
        return false;

    // array of days in each month for a non-leap year
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // adjust for leap year (check note bellow for explanation)
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    // check if the day is within the valid range for the given month
    return day <= daysInMonth[month - 1];
};

/* Note: The rules for determining a leap year are:
    - A year is a leap year if it is divisible by 4.
    - However, if the year is also divisible by 100, it is not a leap year unless:
        the year is also divisible by 400, in which case it is a leap year. */


bool BitcoinExchange::isValidValue(const float value) const
{
    return value >= 0 && value <= 1000;
};

std::string BitcoinExchange::findClosestLowerDate(const std::string &date) const
{
    // Find the first element that is not less than the specified date
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);

    // Check if there is a element that is less than or equal to the specified date
    if (it == database.begin() && it->first != date)
        return ""; 

    // Check if there is no exact match for the specified date in the database
    if (it == database.end() || it->first != date)
    {
        // If the iterator points to the beginning, there is no date in the database
        // that is less than or equal to the specified date
        if (it == database.begin())
            return "";

        // Point to the previous element, which is the closest lower date
        --it;
    }

    return it->first;
}

/* Note: lower_bound return values
    If the container contains an element that is not less than k, lower_bound returns an iterator pointing to the first such element.
If all elements in the container are less than k, lower_bound returns an iterator pointing to the end of the container (container.end()).
*/

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    
    getline(file, line); // skip header

    while (getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = line.substr(0, comma);
        float price = atof(line.substr(comma + 1).c_str());

        if (isValidDate(date))
            database[date] = price; // add date and price to the db map
    }
    file.close();
    return true;
}

/* Note: substr use cases:
    1 argument (substr(pos)): extracts a substring from pos to the end of the string
    2 arguments (substr(pos, len)): extracts a substring sn pos with the specified length len.

*/

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    
    getline(file, line); // skip header

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
