#include <iostream>
#include <fstream>
#include <string>

// Process each log line to extract the message part
std::string line(const std::string& logLine) {
    size_t startPos = logLine.find(": ") + 2; // Find the start position of the message part
    if (startPos != std::string::npos) { // Check if the delimiter was found
        return logLine.substr(startPos); // Return the message part of the log line
    }
    return ""; // Return an empty string if the delimiter is not found
}

void processLogFile(const std::string& fileName) {
    std::ifstream logFile(fileName);
    std::string logLine;
    // Check if the log file opened successfully
    if (!logFile.is_open()) {
        std::cerr << "Unable to open log file" << std::endl;
        return;
    }
    // Read each line from the log file
    while (getline(logFile, logLine)) {
        std::string message = line(logLine); // Corrected function call to 'line' to process each log line
        std::cout << message << std::endl; // Output the processed log message
    }
    // Close the log file
    logFile.close();
}
int main() {
    processLogFile("log.in"); // Call the processLogFile function with a sample log file name
    return 0;
}
