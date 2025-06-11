CC = clang++
LD = clang++
CPPFLAGS = -std=c++17 -I./include
LDFLAGS = -lpthread
ROOTDIR = ./
CP = cp
ECHO = echo
BUILD_DIR = build

# Adjusted for src directory
CPP_SOURCES = src/main.cpp src/log.cpp
CPP_HEADERS = src/log.hpp
C_SOURCES =

APP = app

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))

vpath %.cpp $(sort $(dir $(CPP_SOURCES)))

$(BUILD_DIR)/%.o: %.cpp $(CPP_HEADERS) Makefile | $(BUILD_DIR)
	$(ECHO) compiling $<
	$(CC) -c $(CPPFLAGS) $< -o $@

all: $(BUILD_DIR) $(BUILD_DIR)/$(APP)

run: $(BUILD_DIR)/$(APP)
	./$<

$(BUILD_DIR)/$(APP): $(OBJECTS) Makefile
	$(ECHO) linking $<
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)
	$(ECHO) success

$(BUILD_DIR):
	mkdir -p $@

clean:
	-rm -rf $(BUILD_DIR)

.PHONY: clean all run
