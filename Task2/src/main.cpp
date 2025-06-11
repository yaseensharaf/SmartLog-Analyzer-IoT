#include "log.hpp"
#include <iostream>

int main() {
    Log log;

    // Open the log file and check for failure in one step
    if (!log.create_log("log.in")) {
        std::cerr << "Failed to open log file.\n";
        return 1; // Directly exit if file can't be opened
    }

    // Directly process and print each log entry within the loop
    while (log.next()) {
        // Print details about each log entry without intermediate variables
        std::cout << log.reformat() << std::endl; // Reformatted log entry
        std::cout << log.line() << std::endl;    // Original log message
        std::cout << log.level() << std::endl;   // Log level
    }

    return 0;
}
