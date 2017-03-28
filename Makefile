CPPFLAGS=-g -Wall -std=c++11
BUILD_DIR=.build
USER_SOURCES=src/*/*.cpp
TEST_SOURCES=tests/*.cpp tests/*/*.cpp

ifeq ($(shell uname),Darwin)
SHAREDFLAGS=-shared -undefined dynamic_lookup
else
SHAREDFLAGS=-fPIC -shared
endif

all: $(USER_SOURCES) $(BUILD_DIR)/support.so
	$(CXX) $(CPPFLAGS) $^ -o run

$(BUILD_DIR)/support.so: $(TEST_SOURCES) main.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $^ $(SHAREDFLAGS) -o $(BUILD_DIR)/support.so
