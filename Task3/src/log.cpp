#include "log.hpp"
#include <algorithm>

// Initializes the Log class instance
Log::Log() {}

// Ensures that the file stream is properly closed upon destruction
Log::~Log() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Attempts to open the specified log file for reading
bool Log::create_log(std::string filename) {
    // Opens the file and checks if the operation was successful
    logFile.open(filename);
    return logFile.is_open();
}

// Advances to the next line in the log file
bool Log::next() {
    // Reads the next line if we haven't reached the end of the file
    if (!logFile.eof()) {
        getline(logFile, currentLine); // Retrieve the next line
        return true;// Indicate success
    }
    return false;// End of file reached or other error
}

// Extracts and returns the message part of the current log entry
std::string Log::line() {
    // Locate the start position of the message text
    size_t startPos = currentLine.find(": ") + 2;
    // Extract and return the message if possible
    return startPos != std::string::npos ? currentLine.substr(startPos) : "";
}

// Determines and returns the log level of the current entry
std::string Log::level() {
    // Identify the start and end positions of the log level text
    size_t start = currentLine.find('[') + 1;
    size_t end = currentLine.find(']');
    // Extract, transform to uppercase, and return the log level if valid
    if (start != std::string::npos && end != std::string::npos && end > start) {
        std::string LogLevel = currentLine.substr(start, end - start);
        std::transform(LogLevel.begin(), LogLevel.end(), LogLevel.begin(), ::toupper);
        return LogLevel;
    }
    return ""; // Return empty if no valid log level is found
}

// Combines the current line's message and log level into a single formatted string
std::string Log::reformat() {
    // Construct and return the formatted string
    return line() + " (" + level() + ")";
}
