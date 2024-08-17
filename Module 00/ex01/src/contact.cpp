#include "contact.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

Contact::Contact() {}

Contact::~Contact() {}

std::string getInput(std::string prompt) {
    std::string input;
    do {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEnd of input detected. Exiting." << std::endl;
            exit(0);
        }
        if (input.empty()) {
            std::cout << "Input cannot be empty. Please, try again." << std::endl;
        }
    } while (input.empty());
    return input;
}

void Contact::setContactInfo() {
    firstName = getInput("Enter first name: ");
    lastName = getInput("Enter last name: ");
    nickname = getInput("Enter nickname: ");
    phoneNumber = getInput("Enter phone number: ");
    darkestSecret = getInput("Enter darkest secret: ");

    std::cout << "Contact saved\n" << std::endl;
}

void Contact::displayContactInfo() const
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << '\n' << std::endl;
}

const std::string& Contact::getFirstName() const
{
    return firstName;
}

const std::string& Contact::getLastName() const
{
    return lastName;
}

const std::string& Contact::getNickname() const
{
    return nickname;
}

std::string truncateString(const std::string& str)
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

// void Contact::setContactInfo()
// {
//     std::cout << "Enter first name: ";
//     std::getline(std::cin, firstName);
    
//     std::cout << "Enter last name: ";
//     std::getline(std::cin, lastName);

//     std::cout << "Enter nickname: ";
//     std::getline(std::cin, nickname);

//     std::cout << "Enter phone number: ";
//     std::getline(std::cin, phoneNumber);  

//     std::cout << "Enter darkest secret: ";
//     std::getline(std::cin, darkestSecret);

//     std::cout << "Contact saved\n" << std::endl;
// }