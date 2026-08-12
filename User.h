#pragma once

#include <string>

class User {
private:
    std::string name;
    std::string username;
    std::string password;

public:
    User();
    void registerUser();
    bool login();
    std::string getName() const;
    std::string getUsername() const;
};
