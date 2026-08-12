#include <iostream>
#include <limits>

#include "User.h"
#include "Admin.h"
#include "Schedule.h"
#include "Ticket.h"
#include "FileManager.h"

static void printDivider() {
    std::cout << "------------------------------------------" << std::endl;
}

static void printInputHeader() {
    std::cout << "\n-------- INPUT --------" << std::endl;
}

static void printOutputHeader() {
    std::cout << "\n-------- OUTPUT --------" << std::endl;
}

int main() {

    User user;

    Admin admin;

    Schedule schedule;

    Ticket ticket;


    int choice;


    while (true)
    {
        std::cout << "\n========== BUS/TRAIN RESERVATION ==========" << "\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Admin Login\n";
        std::cout << "4. Exit\n";

        printInputHeader();
        std::cout << "Choice : ";
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {


        case 1:

            user.registerUser();

            break;



        case 2:
            if (user.login())
            {
                std::cout << "\nWelcome " << user.getName() << std::endl;
                while (true)
                {
                    std::cout << "\n--- User Menu ---\n";
                    std::cout << "1. View Available Buses/Trains\n";
                    std::cout << "2. Search Routes\n";
                    std::cout << "3. Reserve Ticket\n";
                    std::cout << "4. Cancel Reservation\n";
                    std::cout << "5. Print Ticket\n";
                    std::cout << "6. View Booking History\n";
                    std::cout << "7. Logout\n";
                    printInputHeader();
                    std::cout << "Choice: ";

                    if (!(std::cin >> choice))
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input.\n";
                        continue;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (choice == 1)
                    {
                        schedule.viewSchedule();
                    }
                    else if (choice == 2)
                    {
                        schedule.searchRoute();
                    }
                    else if (choice == 3)
                    {
                        ticket.bookTicket(user.getUsername(), user.getName());
                    }
                    else if (choice == 4)
                    {
                        ticket.cancelReservation(user.getUsername());
                    }
                    else if (choice == 5)
                    {
                        ticket.printTicket(user.getUsername());
                    }
                    else if (choice == 6)
                    {
                        ticket.viewBookingHistory(user.getUsername());
                    }
                    else if (choice == 7)
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Invalid choice.\n";
                    }
                }
            }
            else
            {
                std::cout << "\nLogin Failed.\n";
            }
            break;

        case 3:
            if (admin.login())
            {
                std::cout << "\nAdmin Login Successful.\n";
                admin.showMenu();
            }
            else
            {
                std::cout << "\nWrong Username or Password.\n";
            }
            break;
        case 4:
            std::cout << "Thank You!\n";
            return 0;



        default:
            std::cout << "\nInvalid Choice.";

        }

    }

}
