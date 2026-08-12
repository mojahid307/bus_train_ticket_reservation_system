#pragma once

#include <string>

class Ticket {
public:
    Ticket();
    void bookTicket(const std::string& username, const std::string& fullName);
    void cancelReservation(const std::string& username);
    void printTicket(const std::string& username);
    void viewBookingHistory(const std::string& username);
};
