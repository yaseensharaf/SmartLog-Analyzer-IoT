#include <iostream>
#include <fstream>
#include <string>

// Extracts the log level from a log line (text between square brackets)
std::string extractLogLevel(const std::string& logLine) {
    size_t startPos = logLine.find('[') + 1; // Find the start of the log level
    size_t endPos = logLine.find(']'); // Find the end of the log level
    if (startPos != std::string::npos && endPos != std::string::npos && startPos < endPos) {
        // Extract and return the log level if both delimiters are found and correctly positioned
        return logLine.substr(startPos, endPos - startPos);
    }
    return ""; // Return an empty string if the log level cannot be extracted
}

// Processes each line of the specified log file to extract and print log levels
void processLogFile(const std::string& fileName) {
    std::ifstream logFile(fileName);
    std::string logLine;

    // Check if the log file was successfully opened
    if (!logFile.is_open()) {
        std::cerr << "Unable to open log file" << std::endl;
        return;
    }

    // Read each line from the file and extract the log level
    while (getline(logFile, logLine)) {
        std::string message = extractLogLevel(logLine);
        std::cout << message << std::endl;
    }

    // Close the file to release resources
    logFile.close();
}
int main() {
    processLogFile("log.in"); // Example log file name
    return 0;
}
