CXX = g++
CXXFLAGS = -std=c++17 -Wall
TEST_LIBS = -lmd4c-html -lCatch2Main -lCatch2
LIBS = -lmd4c-html
TEST_DIR = tests

all: blog

blog: main.o config.o utils.o
	$(CXX) $(CXXFLAGS) main.o config.o -o blog $(LIBS)

main.o: main.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

config.o: config.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c config.cpp

utils.o: utils.cpp utils.hpp
	$(CXX) $(CXXFLAGS) -c utils.cpp

markdown.o: markdown.cpp markdown.hpp
	$(CXX) $(CXXFLAGS) -c markdown.cpp

tests.o: $(TEST_DIR)/tests.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/tests.cpp

tests: tests.o config.o utils.o markdown.o
	g++ -std=c++17 -Wall tests.o config.o utils.o markdown.o -o $(TEST_DIR)/tests $(TEST_LIBS)

check: tests
	$(TEST_DIR)/tests

clean:
	rm -f *.o $(TEST_DIR)/*.o blog $(TEST_DIR)/tests
