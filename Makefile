CPPFLAGS=-g -Wall -Wextra -std=c++11

all: build/ build/demo

build/:
	@mkdir -p build

build/demo: build/main.o build/Role.o build/AdministrativeRole.o build/StudentRole.o build/TeacherRole.o build/GuestRole.o build/Person.o build/Grade.o build/Discipline.o
	g++ -g -o build/demo build/main.o build/Role.o build/AdministrativeRole.o build/StudentRole.o build/TeacherRole.o build/GuestRole.o build/Person.o build/Grade.o build/Discipline.o

build/main.o: src/main.cpp src/Role.hpp src/AdministrativeRole.hpp src/StudentRole.hpp src/TeacherRole.hpp src/GuestRole.hpp src/Person.hpp src/Grade.hpp src/Discipline.hpp
	g++ $(CPPFLAGS) -c -o build/main.o src/main.cpp

build/Role.o: src/Role.cpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/Role.o src/Role.cpp

build/AdministrativeRole.o: src/AdministrativeRole.cpp src/AdministrativeRole.hpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/AdministrativeRole.o src/AdministrativeRole.cpp

build/StudentRole.o: src/StudentRole.cpp src/StudentRole.hpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/StudentRole.o src/StudentRole.cpp

build/TeacherRole.o: src/TeacherRole.cpp src/TeacherRole.hpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/TeacherRole.o src/TeacherRole.cpp

build/GuestRole.o: src/GuestRole.cpp src/GuestRole.hpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/GuestRole.o src/GuestRole.cpp

build/Person.o: src/Person.cpp src/Person.hpp src/Role.hpp
	g++ $(CPPFLAGS) -c -o build/Person.o src/Person.cpp

build/Grade.o: src/Grade.cpp src/Grade.hpp src/Grade.hpp
	g++ $(CPPFLAGS) -c -o build/Grade.o src/Grade.cpp

build/Discipline.o: src/Discipline.cpp src/Discipline.hpp
	g++ $(CPPFLAGS) -c -o build/Discipline.o src/Discipline.cpp


clean:
	@rm -f build/*.o
