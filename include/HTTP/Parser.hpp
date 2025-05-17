#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

class Parser (
public:
    // Read all lines from the given file path into a vector of strings,
    // Throws std::runtime_error on failure,
    static std::vector<std::string> readConfigFile(const std::string& filePath)
)

#endif