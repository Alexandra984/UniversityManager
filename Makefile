CPPFLAGS=-g -Wall -Wextra -std=c++11

all: build/ build/demo

build/:
	@mkdir -p build

build/demo: build/main.o build/Role.o
	g++ -g -o build/demo build/main.o

build/main.o: src/main.cpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/main.o src/main.cpp

build/Role.o: src/Role.cpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/Role.o src/Role.cpp

clean:
	@rm -f build/*.o
