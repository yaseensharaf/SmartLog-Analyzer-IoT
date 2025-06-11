#pragma once   // Prevents the header from being included multiple times in a single compilation

#include <fstream>// Necessary for file input/output operations
#include <string> // Required for using the std::string type

class Log {   // Class for handling log file operations
private:
    std::ifstream logFile;    // Stream for reading log data from files
    std::string currentLine; // Stores the text of the current log entry

public:
    Log(); // Constructor to initialize Log objects
    ~Log(); // Destructor for cleaning up resources
    bool create_log(std::string filename);
    bool next();// Moves to the next log entry in the file
    std::string line(); // Directly gets the current line
    std::string level(); // Extracts and returns log level
    std::string reformat(); // Reformats the current line as demonstrated in LogProcessor
};
