#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
private:
    void (Harl::*complaints[4])(void);
    std::string levels[4];

     enum LogLevel {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        INVALID // Used for unrecognized levels
    };

    LogLevel getLogLevel(std::string level); // Function to map string to enum

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    Harl();  
    ~Harl();

    void complain(std::string level); 
    void filter(std::string level);  
};

#endif
