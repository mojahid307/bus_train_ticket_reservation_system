#pragma once

#include <string>

class Admin {
private:
    std::string username;
    std::string password;

public:
    Admin();
    bool login();
    void showMenu();
};
