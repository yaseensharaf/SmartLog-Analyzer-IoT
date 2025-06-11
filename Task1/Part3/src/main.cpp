#include <iostream>
#include <fstream>
#include <string>

// Reformats a log line by extracting and rearranging its parts
std::string reformatted(const std::string& logLine) {
    size_t startPos = logLine.find("[") + 1; // Start of log level
    size_t endPos = logLine.find("]"); // End of log level
    size_t Pos = logLine.find(": ") + 2; // Start of the main log message

    if (startPos != std::string::npos && endPos != std::string::npos && startPos < endPos && Pos != std::string::npos) {
        // Ensure all positions are valid before proceeding
        std::string messageLevel = logLine.substr(startPos, endPos - startPos); // Extract log level
        std::string messageContent = logLine.substr(Pos); // Extract main message
        return messageContent + " (" + messageLevel + ")"; // Return reformatted line
    }
    // Return the original line if the expected format is not found
    return logLine;
}

// Processes the specified log file, reformatting and printing each line
void processLogFile(const std::string& fileName) {
    std::ifstream logFile(fileName);
    std::string logLine;

    // Check for successful file opening
    if (!logFile.is_open()) {
        std::cerr << "Unable to open log file" << std::endl;
        return;
    }

    // Read and process each line of the file
    while (getline(logFile, logLine)) {
        std::string message = reformatted(logLine);
        std::cout << message << std::endl; // Print the reformatted log line
    }

    // Close the file once done
    logFile.close();
}
int main() {
    processLogFile("log.in"); // Example usage with a sample log file
    return 0;
}
