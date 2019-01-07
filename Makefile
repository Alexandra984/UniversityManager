all: build/ src/*.cpp src/*.hpp
	g++ -Wall -Wextra -o build/exec src/main.cpp src/room.cpp src/person.cpp src/student.cpp src/teacher.cpp src/adminstrative.cpp src/subject.cpp src/grade_list.cpp src/activity.cpp src/administrative_activity.cpp src/didactic_activity.cpp src/repository.hpp src/room_repository.cpp src/activity_repository.cpp src/person_repository.cpp src/student_record.cpp src/subject_repository.cpp

build/:
	@mkdir -p build
