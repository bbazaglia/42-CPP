#include "fileReplacer.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <searchString> <replaceString>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string searchString = argv[2];
    std::string replaceString = argv[3];

    if (searchString.empty()) {
        std::cerr << "Error: The search string cannot be empty." << std::endl;
        return 1;
    }

    FileReplacer replacer(filename, searchString, replaceString);
    replacer.process();

    return 0;
}
