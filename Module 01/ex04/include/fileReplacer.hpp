#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <iostream>
#include <string>
#include <fstream>

class FileReplacer {
public:
    // Pass a string as a const reference to avoid creating a copy of the string.
    FileReplacer(const std::string& filename, const std::string& searchString, const std::string& replaceString);
    ~FileReplacer();

    void process();

private:
    std::string filename;
    std::string searchString;
    std::string replaceString;
    std::string content;

    bool readFile();
    bool writeFile();
};

std::string replaceSubstring(std::string str, const std::string& oldSubstring, const std::string& newSubstring);

#endif 
