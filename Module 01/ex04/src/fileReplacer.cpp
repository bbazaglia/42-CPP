#include "fileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& searchString, const std::string& replaceString)
    : filename(filename), searchString(searchString), replaceString(replaceString) {}

FileReplacer::~FileReplacer() {}

void FileReplacer::process() {
    if (!readFile()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    content = replaceSubstring(content, searchString, replaceString);

    if (!writeFile()) {
        std::cerr << "Error: Could not write to file " << filename << ".replace" << std::endl;
    }
}

/*
 * assign() replaces the contents of the string with the characters in the specified range.
 * The arguments passed to assign are a pair of iterators:
 * The first iterator (std::istreambuf_iterator<char>(infile)) marks the start of the range.
 * The second iterator (std::istreambuf_iterator<char>()) marks the end of the range.
*/
bool FileReplacer::readFile() {
    std::ifstream infile(filename.c_str()); 
    if (!infile.is_open()) {
        return false;
    }

    // Read the entire content of the file into the 'content' string
    content.assign((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
   
    infile.close();
    return true;
}

/* 
 * String Streaming (std::stringstream) is used to convert data to and from strings.
 * ofstream class is used to write/output data to a file.
 * ifstream class is used to read/input data from a file.
 * The std::ofstream class has a constructor that takes a const char* as an argument
 * c_str() is used when you need to pass a std::string to a function that expects a c-style string (const char*)
*/
bool FileReplacer::writeFile() {
    std::ofstream outfile((filename + ".replace").c_str()); 
    if (!outfile.is_open()) {
        return false;
    }

    // Write the modified content to the file
    outfile << content;
    outfile.close();
    return true;
}

std::string replaceSubstring(std::string str, const std::string& oldSubstring, const std::string& newSubstring) {
    // Find the first occurrence of oldSubstring
    size_t pos = str.find(oldSubstring);
    
    while (pos != std::string::npos) {
        str.erase(pos, oldSubstring.length());
        str.insert(pos, newSubstring);

        // Find the next occurrence after the replaced substring
        pos = str.find(oldSubstring, pos + newSubstring.length());
    }
    
    return str;
}
