// #include <fstream>   // For file reading
// #include <string>    // For std::string
// #include <iostream>  // For error/output (optional)
// #include <sstream>   // For string parsing (optional)
// #include <vector>    // For storing lines or tokens (optional)


#include "Parser.hpp"
#include <fstream>
#include <stdexcept>

std::vector<std::string> Parser::readConfigFile(const std::string& filePath) {
    std::ifstream file(filePath.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open config file: " + filePath);
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}