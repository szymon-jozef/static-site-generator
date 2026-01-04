CXX = g++
CXXFLAGS = -std=c++17 -Wall
TEST_LIBS = -lmd4c-html -lCatch2Main -lCatch2
LIBS = -lmd4c-html

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

tests: tests.o config.o utils.o markdown.o
	g++ -std=c++17 -Wall tests.o config.o utils.o markdown.o -o tests $(TEST_LIBS)

tests.o: tests.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c tests.cpp

check: tests
	./tests

clean:
	rm -f *.o blog tests
