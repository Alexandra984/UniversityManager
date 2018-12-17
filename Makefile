CPPFLAGS=-g -Wall -Wextra -std=c++11

all: build/ build/demo

build/:
	@mkdir -p build

build/demo: build/main.o build/Role.o build/AdministrativeRole.o build/StudentRole.o build/TeacherRole.o
	g++ -g -o build/demo build/main.o build/Role.o build/AdministrativeRole.o build/StudentRole.o build/TeacherRole.o

build/main.o: src/main.cpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/main.o src/main.cpp

build/Role.o: src/Role.cpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/Role.o src/Role.cpp

build/AdministrativeRole.o: src/AdministrativeRole.cpp src/AdministrativeRole.hpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/AdministrativeRole.o src/AdministrativeRole.cpp

build/StudentRole.o: src/StudentRole.cpp src/StudentRole.hpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/StudentRole.o src/StudentRole.cpp

build/TeacherRole.o: src/TeacherRole.cpp src/TeacherRole.hpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/TeacherRole.o src/TeacherRole.cpp

clean:
	@rm -f build/*.o
