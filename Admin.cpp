#include "Admin.h"
#include "Schedule.h"
#include "FileManager.h"
#include <iostream>
#include <limits>

Admin::Admin() : username(""), password("") {}

bool Admin::login() {
    std::cout << "\n--- Admin Login ---\n";
    std::cout << "Username: ";
    std::getline(std::cin >> std::ws, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);
    return username == "admin" && password == "admin";
}

void Admin::showMenu() {
    Schedule schedule;
    int choice = 0;

    while (true) {
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. View Schedule\n";
        std::cout << "2. Add Schedule Entry\n";
        std::cout << "3. Update Schedule Entry\n";
        std::cout << "4. Delete Schedule Entry\n";
        std::cout << "5. View Passenger List\n";
        std::cout << "6. Generate Booking Report\n";
        std::cout << "7. Exit Admin Menu\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            schedule.viewSchedule();
        } else if (choice == 2) {
            schedule.addScheduleEntry();
        } else if (choice == 3) {
            schedule.updateScheduleEntry();
        } else if (choice == 4) {
            schedule.deleteScheduleEntry();
        } else if (choice == 5) {
            auto tickets = FileManager::readLines("tickets.txt");
            std::cout << "\n--- Passenger List ---\n";
            for (const auto& ticket : tickets) {
                std::cout << ticket << "\n";
            }
            if (tickets.empty()) {
                std::cout << "No passenger records found.\n";
            }
        } else if (choice == 6) {
            auto tickets = FileManager::readLines("tickets.txt");
            std::cout << "\n--- Booking Report ---\n";
            std::cout << "Total Reservations: " << tickets.size() << "\n";
            for (const auto& ticket : tickets) {
                std::cout << ticket << "\n";
            }
            if (tickets.empty()) {
                std::cout << "No bookings found.\n";
            }
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}
