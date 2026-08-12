#include "Ticket.h"
#include "FileManager.h"
#include "Schedule.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

static const char* TICKETS_FILE = "tickets.txt";

Ticket::Ticket() {}

void Ticket::bookTicket(const std::string& username, const std::string& fullName) {
    Schedule schedule;
    schedule.viewSchedule();

    std::cout << "\n--- Ticket Booking ---\n";
    std::cout << "Enter schedule number to book: ";
    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto entries = FileManager::readLines("schedule.txt");
    if (choice < 1 || choice > static_cast<int>(entries.size())) {
        std::cout << "Invalid schedule choice.\n";
        return;
    }

    std::cout << "Enter seat number: ";
    std::string seat;
    std::getline(std::cin >> std::ws, seat);
    if (seat.empty()) {
        std::cout << "Seat selection cannot be empty.\n";
        return;
    }

    const std::string ticketLine = username + "," + fullName + "," + seat + "," + entries[choice - 1];
    if (FileManager::saveLine(TICKETS_FILE, ticketLine)) {
        std::cout << "Ticket booked successfully.\n";
    } else {
        std::cout << "Failed to save ticket.\n";
    }
}

void Ticket::cancelReservation(const std::string& username) {
    auto tickets = FileManager::readLines(TICKETS_FILE);
    std::vector<std::string> remaining;
    bool found = false;

    for (const auto& ticket : tickets) {
        if (ticket.rfind(username + ",", 0) == 0) {
            found = true;
        } else {
            remaining.push_back(ticket);
        }
    }

    if (!found) {
        std::cout << "No reservations found to cancel.\n";
        return;
    }

    if (FileManager::overwriteLines(TICKETS_FILE, remaining)) {
        std::cout << "Reservation cancelled successfully.\n";
    } else {
        std::cout << "Failed to update reservation data.\n";
    }
}

static void printDivider(int width) {
    std::cout << "+" << std::string(width - 2, '-') << "+" << std::endl;
}

static void printTicketDetails(const std::string& ticketLine) {
    std::istringstream iss(ticketLine);
    std::string username;
    std::string fullName;
    std::string seat;
    std::string vehicle;
    std::string origin;
    std::string destination;
    std::string time;

    std::getline(iss, username, ',');
    std::getline(iss, fullName, ',');
    std::getline(iss, seat, ',');
    std::getline(iss, vehicle, ',');
    std::getline(iss, origin, ',');
    std::getline(iss, destination, ',');
    std::getline(iss, time, ',');

    const int boxWidth = 58;
    const int labelWidth = 14;
    const int valueWidth = boxWidth - labelWidth - 6;

    printDivider(boxWidth);
    std::cout << "| " << std::setw(boxWidth - 4) << std::left << "TICKET DETAILS" << " |\n";
    printDivider(boxWidth);
    std::cout << "| " << std::left << std::setw(labelWidth) << "Passenger" << ": " << std::setw(valueWidth) << fullName << " |\n";
    std::cout << "| " << std::left << std::setw(labelWidth) << "Username" << ": " << std::setw(valueWidth) << username << " |\n";
    std::cout << "| " << std::left << std::setw(labelWidth) << "Seat" << ": " << std::setw(valueWidth) << seat << " |\n";
    std::cout << "| " << std::left << std::setw(labelWidth) << "Vehicle" << ": " << std::setw(valueWidth) << vehicle << " |\n";
    std::cout << "| " << std::left << std::setw(labelWidth) << "From" << ": " << std::setw(valueWidth) << origin << " |\n";
    std::cout << "| " << std::left << std::setw(labelWidth) << "To" << ": " << std::setw(valueWidth) << destination << " |\n";
    std::cout << "| " << std::left << std::setw(labelWidth) << "Departure" << ": " << std::setw(valueWidth) << time << " |\n";
    printDivider(boxWidth);
}

void Ticket::printTicket(const std::string& username) {
    auto tickets = FileManager::readLines(TICKETS_FILE);
    bool found = false;

    for (const auto& ticket : tickets) {
        if (ticket.rfind(username + ",", 0) == 0) {
            found = true;
            printTicketDetails(ticket);
            std::cout << std::endl;
        }
    }

    if (!found) {
        std::cout << "No tickets found for this user." << std::endl;
    }
}

void Ticket::viewBookingHistory(const std::string& username) {
    auto tickets = FileManager::readLines(TICKETS_FILE);
    bool found = false;

    std::cout << "\n--- Booking History ---\n";
    for (const auto& ticket : tickets) {
        if (ticket.rfind(username + ",", 0) == 0) {
            found = true;
            std::cout << ticket << "\n";
        }
    }

    if (!found) {
        std::cout << "No booking history found.\n";
    }
}
