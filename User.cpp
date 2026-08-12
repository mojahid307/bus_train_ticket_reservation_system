#include "User.h"
#include "FileManager.h"
#include <iostream>
#include <sstream>

static const char* USERS_FILE = "users.txt";

User::User() : name(""), username(""), password("") {}

void User::registerUser() {
    std::cout << "\n--- User Registration ---\n";
    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Username: ";
    std::getline(std::cin, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);

    auto lines = FileManager::readLines(USERS_FILE);
    for (const auto& line : lines) {
        std::istringstream iss(line);
        std::string existingUsername;
        std::getline(iss, existingUsername, ',');
        if (existingUsername == username) {
            std::cout << "Username already exists.\n";
            return;
        }
    }

    if (FileManager::saveLine(USERS_FILE, username + "," + password + "," + name)) {
        std::cout << "Registration complete.\n";
    } else {
        std::cout << "Failed to save user data.\n";
    }
}

bool User::login() {
    std::cout << "\n--- User Login ---\n";
    std::cout << "Username: ";
    std::getline(std::cin >> std::ws, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);

    auto lines = FileManager::readLines(USERS_FILE);
    for (const auto& line : lines) {
        std::istringstream iss(line);
        std::string storedUsername;
        std::string storedPassword;
        std::string storedName;
        std::getline(iss, storedUsername, ',');
        std::getline(iss, storedPassword, ',');
        std::getline(iss, storedName, ',');
        if (storedUsername == username && storedPassword == password) {
            name = storedName;
            return true;
        }
    }
    return false;
}

std::string User::getName() const {
    return name;
}

std::string User::getUsername() const {
    return username;
}
