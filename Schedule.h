#pragma once

#include <string>
#include <vector>

class Schedule {
private:
    std::vector<std::string> entries;
    void loadSchedule();
    void saveSchedule();

public:
    Schedule();
    void viewSchedule();
    void addScheduleEntry();
    void updateScheduleEntry();
    void deleteScheduleEntry();
    void searchRoute();
};
