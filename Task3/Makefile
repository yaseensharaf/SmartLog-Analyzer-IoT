CC = clang++
CPPFLAGS = -std=c++17 -I./include -I./simpletest
LDFLAGS = -lpthread
BUILD_DIR = build

# Application settings
APP = app
APP_SOURCES = src/main.cpp src/log.cpp
APP_OBJECTS = $(patsubst src/%.cpp, $(BUILD_DIR)/%.o, $(APP_SOURCES))

# Test settings
TEST_APP = log_tests
TEST_SOURCES = src/log_tests.cpp src/log.cpp simpletest/simpletest.cpp
TEST_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(TEST_SOURCES)))

# Ensure 'all' and 'test' targets don't actually represent files.
.PHONY: all test clean

all: $(BUILD_DIR)/$(APP)

# Build and run tests
test: $(BUILD_DIR) $(TEST_OBJECTS)
	$(CC) $(LDFLAGS) -o $(BUILD_DIR)/$(TEST_APP) $(TEST_OBJECTS)
	./$(BUILD_DIR)/$(TEST_APP)


$(BUILD_DIR)/$(APP): $(APP_OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/$(TEST_APP): $(TEST_OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^
	./$@

# Compile .cpp files to .o files from src directory
$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

# Compile .cpp files to .o files from simpletest directory
$(BUILD_DIR)/%.o: simpletest/%.cpp | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
