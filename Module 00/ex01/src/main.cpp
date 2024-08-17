#include "phonebook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            if (std::cin.eof()) 
                std::cout << "\nEOF detected. Exiting program." << std::endl;
            break; 
        }

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command! Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }

    return 0;
}
