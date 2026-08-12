#include "Schedule.h"
#include "FileManager.h"
#include <iostream>
#include <sstream>

static const char* SCHEDULE_FILE = "schedule.txt";

Schedule::Schedule() {
    loadSchedule();
}

void Schedule::saveSchedule() {
    FileManager::overwriteLines(SCHEDULE_FILE, entries);
}

void Schedule::loadSchedule() {
    entries = FileManager::readLines(SCHEDULE_FILE);
    if (entries.empty()) {
        entries = {
            "BUS 101,City A,City B,09:00",
            "TRAIN 302,City C,City D,14:30"
        };
        saveSchedule();
    }
}

void Schedule::viewSchedule() {
    std::cout << "\n--- Available Schedule ---\n";
    loadSchedule();
    for (size_t i = 0; i < entries.size(); ++i) {
        std::cout << i + 1 << ". " << entries[i] << "\n";
    }
    if (entries.empty()) {
        std::cout << "No schedule entries available.\n";
    }
}

void Schedule::addScheduleEntry() {
    std::cout << "\nEnter schedule entry (Format: Vehicle,From,To,Time): ";
    std::string entry;
    std::getline(std::cin >> std::ws, entry);
    if (entry.empty()) {
        std::cout << "Entry cannot be empty.\n";
        return;
    }
    entries.push_back(entry);
    saveSchedule();
    std::cout << "Schedule entry added.\n";
}

void Schedule::updateScheduleEntry() {
    loadSchedule();
    viewSchedule();
    std::cout << "\nEnter schedule number to update: ";
    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice < 1 || choice > static_cast<int>(entries.size())) {
        std::cout << "Invalid schedule choice.\n";
        return;
    }

    std::cout << "Enter updated schedule entry (Format: Vehicle,From,To,Time): ";
    std::string entry;
    std::getline(std::cin >> std::ws, entry);
    if (entry.empty()) {
        std::cout << "Entry cannot be empty.\n";
        return;
    }

    entries[choice - 1] = entry;
    saveSchedule();
    std::cout << "Schedule updated successfully.\n";
}

void Schedule::deleteScheduleEntry() {
    loadSchedule();
    viewSchedule();
    std::cout << "\nEnter schedule number to delete: ";
    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice < 1 || choice > static_cast<int>(entries.size())) {
        std::cout << "Invalid schedule choice.\n";
        return;
    }

    entries.erase(entries.begin() + (choice - 1));
    saveSchedule();
    std::cout << "Schedule entry deleted successfully.\n";
}

void Schedule::searchRoute() {
    loadSchedule();
    std::string from;
    std::string to;

    std::cout << "\nEnter origin city: ";
    std::getline(std::cin >> std::ws, from);
    std::cout << "Enter destination city: ";
    std::getline(std::cin, to);

    if (from.empty() && to.empty()) {
        std::cout << "Search terms cannot both be empty.\n";
        return;
    }

    std::cout << "\n--- Search Results ---\n";
    bool found = false;
    for (size_t i = 0; i < entries.size(); ++i) {
        std::istringstream iss(entries[i]);
        std::string vehicle, origin, destination, time;
        std::getline(iss, vehicle, ',');
        std::getline(iss, origin, ',');
        std::getline(iss, destination, ',');
        std::getline(iss, time, ',');

        bool fromMatch = from.empty() || origin.find(from) != std::string::npos;
        bool toMatch = to.empty() || destination.find(to) != std::string::npos;
        if (fromMatch && toMatch) {
            std::cout << i + 1 << ". " << entries[i] << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No route matches found.\n";
    }
}
