
#include "simpletest.h"
#include "log.hpp"

#include <string>
using namespace std;

char const * groups[] = {"Log",};

// Test 1: Successfully opening a log file
DEFINE_TEST_G(LogOpenTest, Log) {
    Log log;
    // Test opens the log.in file assuming it exists
    bool success = log.create_log("log.in");
    TEST_MESSAGE(success == true, "Failed to open log file!");
}

// Test Case 2: Reading from Log File
DEFINE_TEST_G(ReadingFromLogInFile, Log) {
    Log log;
    log.create_log("log.in"); // Ensure the "log.in" file exists and contains at least one line for the test
    bool success = log.next();
    TEST_MESSAGE(success, "Should be able to read from the 'log.in' file.");
}

// Test Case 3: Confirming 'log.in' File Contains Data
DEFINE_TEST_G(LogInFileContentCheck, Log) {
    Log log;
    // Open 'log.in', assuming it exists for this scenario
    bool openSuccess = log.create_log("log.in");
    TEST_MESSAGE(openSuccess, "Failed to open 'log.in'; file does not exist or is inaccessible.");

    // Attempt to read from 'log.in' to confirm it contains data
    bool readSuccess = log.next();
    TEST_MESSAGE(readSuccess, "'log.in' is empty or could not be read, expected to contain data.");
}

// Test Case 4: Verifying Correct Log Level Extraction
DEFINE_TEST_G(VerifyLogLevelInLogIn, Log) {
    Log logProcessor; // Create a log processing instance
    // Initiates opening of 'log.in', expected to contain log entries for this test
    bool isLogOpened = logProcessor.create_log("log.in");
    TEST_MESSAGE(isLogOpened, "Opening 'log.in' failed, cannot proceed with log level identification test.");

    // Proceed if there's at least one entry to analyze for a log level
    if (logProcessor.next()) {
        std::string detectedLogLevel = logProcessor.level(); // Attempt to pinpoint the log level in the current log entry
        TEST_MESSAGE(!detectedLogLevel.empty(), "Log level identification in 'log.in' resulted in an empty string.");
        // Further assertions could include checking the detected log level against expected values, enhancing test robustness
    } else {
        TEST_MESSAGE(false, "No entries available in 'log.in' for log level identification.");
    }
}

// Test 5: Verifying 'log.in' File's Readability After Initial Read
DEFINE_TEST_G(LogInFileSequentialReadTest, Log) {
    Log log;
    // Open 'log.in' for the test
    bool openSuccess = log.create_log("log.in");
    TEST_MESSAGE(openSuccess, "'log.in' failed to open on the first attempt.");

    // Read the first line to simulate initial use
    bool initialReadSuccess = log.next();
    TEST_MESSAGE(initialReadSuccess, "Initial read from 'log.in' failed, cannot proceed with sequential read test.");

    // Attempt to read a second line, verifying continued readability
    bool continuedReadSuccess = log.next();
    TEST_MESSAGE(continuedReadSuccess, "Failed to read from 'log.in' after an initial read, expected sequential readability.");
}

int main() {
    bool pass = true;
    for (auto group : groups) {
        pass &= TestFixture::ExecuteTestGroup(group, TestFixture::Verbose);
    }
    return pass ? 0 : 1;
}
