#include <string>
#include <ctime>

#include <iostream>

using namespace std;

void logger(char type, string msg) {
    auto current_time = time(0);
    char current_time_str[size("yyyy-mm-ddThh:mm:ssZ")];
    tm calendar_datetime;
    gmtime_s(&calendar_datetime, &current_time);
    strftime(current_time_str, size(current_time_str), "%FT%TZ", &calendar_datetime);
    current_time_str[strlen(current_time_str) - 1] = '\0';

    if (type == 0) {
        cout << "\033[34m" << "[" << current_time_str << "]" << " INFO: " << msg << "\033[0m\n";
    }
    else if (type == 1) {
        cout << "\033[32m" << "[" << current_time_str << "]" << " Success: " << msg << "\033[0m\n";
    }
    else if (type == 2) {
        cout << "\033[31m" << "[" << current_time_str << "]" << " Error: " << msg << "\033[0m\n";
    }
}