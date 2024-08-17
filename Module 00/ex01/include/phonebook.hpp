#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

const int MAX_CONTACTS = 8;

class PhoneBook
{
private:
    Contact contacts[MAX_CONTACTS];
    int contactCount;
    int currentIndex;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact();
};

#endif
