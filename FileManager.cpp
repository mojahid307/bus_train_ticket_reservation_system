#include "FileManager.h"
#include <fstream>

bool FileManager::saveLine(const std::string& path, const std::string& line) {
    std::ofstream file(path, std::ios::app);
    if (!file) {
        return false;
    }
    file << line << '\n';
    return true;
}

std::vector<std::string> FileManager::readLines(const std::string& path) {
    std::vector<std::string> lines;
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    return lines;
}

bool FileManager::overwriteLines(const std::string& path, const std::vector<std::string>& lines) {
    std::ofstream file(path, std::ios::trunc);
    if (!file) {
        return false;
    }
    for (const auto& line : lines) {
        file << line << '\n';
    }
    return true;
}
