#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;


public:
    Contact();
    ~Contact();

    void setContactInfo();
    void displayContactInfo() const;

    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
};

std::string truncateString(const std::string& str);
std::string getInput(std::string prompt);

#endif
