#include "phonebook.hpp"
#include <sstream>
#include <iostream>
#include <limits>
#include <iomanip> 

PhoneBook::PhoneBook() : contactCount(0), currentIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
    contacts[currentIndex].setContactInfo();
    currentIndex = (currentIndex + 1) % MAX_CONTACTS;
    if (contactCount < MAX_CONTACTS) {
        contactCount++;
    }
}

int stringToInt(const std::string& str)
{
    std::stringstream ss(str);
    int result;
    if (!(ss >> result)) {
        throw std::invalid_argument("Invalid argument");
    }
    return result;
}

void PhoneBook::searchContact()
{
    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }

    std::cout << "Saved contacts:" << std::endl;
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "-------------------------------------------" << '\n' << std::endl;

    std::cout << "Enter index of contact to be displayed: ";
    std::string stringIndex;
    std::getline(std::cin, stringIndex);

    try
    {
        int index = stringToInt(stringIndex);
        if (index < 0 || index >= contactCount)
        {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        contacts[index].displayContactInfo();
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Invalid index" << std::endl;
    }
}
