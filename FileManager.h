#pragma once

#include <string>
#include <vector>

class FileManager {
public:
    static bool saveLine(const std::string& path, const std::string& line);
    static std::vector<std::string> readLines(const std::string& path);
    static bool overwriteLines(const std::string& path, const std::vector<std::string>& lines);
};
