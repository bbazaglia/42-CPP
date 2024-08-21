#include "Harl.hpp"

/*
* The initialization of the 'complaints' array with pointers to the corresponding member functions is done in the constructor 
* to ensure that the array is a member of the Harl class, making it accessible across different methods (complain and filter).
*/
Harl::Harl() {
    complaints[DEBUG] = &Harl::debug;
    complaints[INFO] = &Harl::info;
    complaints[WARNING] = &Harl::warning;
    complaints[ERROR] = &Harl::error;
}

Harl::~Harl() {}

Harl::LogLevel Harl::getLogLevel(std::string level) {
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return INVALID;
}

void Harl::filter(std::string level) {
    LogLevel startLevel = getLogLevel(level);

    switch (startLevel) {
        case DEBUG:
            (this->*complaints[DEBUG])();
        case INFO:
            (this->*complaints[INFO])();
        case WARNING:
            (this->*complaints[WARNING])();
        case ERROR:
            (this->*complaints[ERROR])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
