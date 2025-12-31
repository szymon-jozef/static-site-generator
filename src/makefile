CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: blog

blog: main.o config.o
	$(CXX) $(CXXFLAGS) main.o config.o -o blog

main.o: main.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

config.o: config.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c config.cpp

tests: tests.o config.o
	g++ -std=c++17 -Wall tests.o config.o -o tests -lCatch2Main -lCatch2

tests.o: tests.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c tests.cpp

check: tests
	./tests

clean:
	rm -f *.o blog tests
