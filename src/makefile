CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: blog

blog: main.o config.o
	$(CXX) $(CXXFLAGS) main.o config.o -o blog

main.o: main.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

config.o: config.cpp config.hpp
	$(CXX) $(CXXFLAGS) -c config.cpp

clean:
	rm -f *.o blog
