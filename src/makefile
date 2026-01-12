CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I .
LIBS = -lmd4c-html
TEST_LIBS = -lmd4c-html -lCatch2Main -lCatch2

BUILD_DIR = build

SOURCES = main.cpp \
          config/config.cpp \
          format/format.cpp \
          markdown/markdown.cpp \
		  io/io.cpp \
		  builder/builder.cpp

OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

TEST_SOURCES = tests.cpp \
               config/config.cpp \
               format/format.cpp \
               markdown/markdown.cpp \
			   io/io.cpp \
			   builder/builder.cpp

TEST_OBJECTS = $(TEST_SOURCES:%.cpp=$(BUILD_DIR)/%.o)

TARGET = blog
TEST_TARGET = tests

.PHONY: all clean test directories

all: directories $(TARGET)

directories:
	@mkdir -p $(BUILD_DIR)/config
	@mkdir -p $(BUILD_DIR)/format
	@mkdir -p $(BUILD_DIR)/io
	@mkdir -p $(BUILD_DIR)/markdown
	@mkdir -p $(BUILD_DIR)/builder

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(TEST_LIBS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: directories $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET) $(TEST_TARGET)

rebuild: clean all
