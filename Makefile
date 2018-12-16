CPPFLAGS=-g -Wall -Wextra -std=c++11

all: build/ build/demo

build/:
	@mkdir -p build

build/demo: build/main.o
	g++ -g -o build/demo build/main.o

build/main.o: src/main.cpp
	g++ $(CPPFLAGS) -c -o build/main.o src/main.cpp

clean:
	@rm -f build/*.o
