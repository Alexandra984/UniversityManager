#include <iostream>
#include "room.hpp"
#include "person.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "administrative.hpp"
#include "subject.hpp"
#include "grade_list.hpp"
#include "activity.hpp"
#include "administrative_activity.hpp"
#include "didactic_activity.hpp"
#include "repository.hpp"
#include "room_repository.hpp"
#include "subject_repository.hpp"
#include "activity_repository.hpp"
#include "person_repository.hpp"
#include "student_record.hpp"

int main() {
  Room room("Sala 2");
  std::cout << room.GetName() << std::endl;
  room.SetName("Sala 1");
  std::cout << room.GetName() << std::endl;

  Student student("Maria", "Ionescu", "maria@yahoo.com", 234567123, 1, 2, 101);

  std::cout << student.GetFirstName() << " " << student.GetLastName() << " " <<
    student.GetEmail() << " " << student.GetCnp() <<  " " <<
    student.GetId() << " " << student.GetYear() << " " << student.GetGroupNo()
    << std::endl;

  student.SetFirstName("Ana");
  student.SetLastName("Popescu");
  student.SetEmail("ana@yahoo.com");
  student.SetCnp(290061455);
  student.SetId(2);
  student.SetYear(1);
  student.SetGroupNo(102);

  std::cout << student.GetType() << std::endl;

  std::cout << student.GetFirstName() << " " << student.GetLastName() << " " <<
    student.GetEmail() << " " << student.GetCnp() <<  " " <<
    student.GetId() << " " << student.GetYear() << " " << student.GetGroupNo()
    << std::endl;

  Teacher teacher("Radu", "Gramatovici", "radu@yahoo.com", 1682348574, "math",
      "decan");

  std::cout << teacher.GetFirstName() << " " << teacher.GetLastName() << " " <<
    teacher.GetEmail() << " " << teacher.GetCnp() <<  " " <<
    teacher.GetStudies() << " " << teacher.GetFunction() << " " << std::endl;

  teacher.SetFirstName("Paul");
  teacher.SetLastName("Irofti");
  teacher.SetEmail("paulirofti@yahoo.com");
  teacher.SetCnp(13847455);
  teacher.SetStudies("Info");
  teacher.SetFunction("Lector");

  std::cout << teacher.GetFirstName() << " " << teacher.GetLastName() << " " <<
    teacher.GetEmail() << " " << teacher.GetCnp() <<  " " <<
    teacher.GetStudies() << " " << teacher.GetFunction() << " " << std::endl;

  std::cout << teacher.GetType() << std::endl;

  Administrative administrator("Baba", "Vanga", "babavanga@yahoo.com", 123456);

  std::cout << administrator.GetFirstName() << " " << administrator.GetLastName() << " " <<
    administrator.GetEmail() << " " << administrator.GetCnp() << std::endl;

  std::cout << administrator.GetType() << std::endl;

  Subject subject("Math");
  std::cout << subject.GetName() << std::endl;

  subject.SetName("Calculus");
  std::cout << subject.GetName() << std::endl;

  Subject* s = new Subject("English");
  GradeList gradelist(s);
  gradelist.AddGrade(10);
  gradelist.AddGrade(9);
  gradelist.AddGrade(9);
  std::vector<int> grades = gradelist.GetGrades();
  for (int i = 0; i < (int)grades.size(); ++i ) {
    std::cout << grades[i] << " ";
  }
  std::cout << "\n";

  Administrative* person1 = &administrator;
  Room* r = &room;
  AdministrativeActivity activity1(person1, r, "Inginer");
  std::cout << activity1.GetOwner()->GetLastName() << " " << activity1.GetRoom()->GetName() << " " <<
    activity1.GetDescription() << std::endl;

 Administrative administrator1("Radu", "Boriga", "radub@yahoo.com", 123455);
 Person* person11 =  &administrator1;
 activity1.SetOwner(person11);

 Room room1("Sala 12");
 Room* room11 = &room1;
 activity1.SetRoom(room11);

 activity1.SetDescription("Seminar Tehnici de programare");

  std::cout << activity1.GetOwner()->GetLastName() << " " << activity1.GetRoom()->GetName() << " " <<
    activity1.GetDescription() << std::endl;
  Student* stud = &student;
  activity1.AddParticipant(stud);
  std::vector<Person*> participants = activity1.GetParticipants();

  for(int i = 0; i < (int)participants.size(); ++i) {
    std::cout << participants[i]->GetLastName() << " ";
  }
  std::cout << "\n";

  Teacher* teach = &teacher;
  activity1.AddParticipant(teach);

  for(int i = 0; i < (int)participants.size(); ++i) {
    std::cout << participants[i]->GetLastName() << " ";
  }

  std::cout << "\n";

  DidacticActivity didacticActivity(teach, room11, "Laborator POO", s);

  std::cout << didacticActivity.GetSubject()->GetName() << std::endl;

  Subject sub2("POO");
  Subject* s2 = &sub2;
  didacticActivity.SetSubject(s2);

  std::cout << didacticActivity.GetSubject()->GetName() << std::endl;

  Teacher teacher3("Dobrovat", "Anca", "ancad@yahhoo.com", 1234555, "POO", "lector");
  Person* p3 = &teacher3;
  didacticActivity.SetOwner(p3);
  std::cout << didacticActivity.GetOwner()->GetLastName() << std::endl;

  Student student3("Ana-Maria", "Popescu", "anaa@yahoo.com", 2311, 14, 4, 432);
  Student* s3 = &student3;
  didacticActivity.SetOwner(s3);
  std::cout << didacticActivity.GetOwner()->GetLastName() << std::endl;

  Room* r3 = new Room("Sala 121");

  didacticActivity.SetRoom(r3);
  std::cout << didacticActivity.GetRoom()->GetName() << std::endl;

  didacticActivity.AddParticipant(s3);

  std::vector<Person*> participants2 = didacticActivity.GetParticipants();

  for (int i = 0; i <(int)participants2.size(); ++i) {
    std::cout << participants2[i]->GetLastName() << std::endl;
  }

  Repository<Student> StudentRepository;

  Student* s4 = new Student("Robert", "Vulpescu", "rbb@yahoo.com", 4311, 12, 5, 501);

  StudentRepository.Add(s4);

  std::vector<Student*> students = StudentRepository.GetAll();

  Student* s5 = new Student("Andreea", "Negrescu", "anerg@yahoo.com", 422311, 20, 1, 101);
  StudentRepository.Add(s5);

  for(int i = 0; i < (int)students.size(); ++i) {
    std::cout << students[i]->GetLastName() << std::endl;
  }

  int size = StudentRepository.size();
  std::cout << size << std::endl;

  StudentRepository.Remove(s4);

  students = StudentRepository.GetAll();

  for(int i = 0; i < (int)students.size(); ++i) {
    std::cout << students[i]->GetLastName() << std::endl;
  }

  RoomRepository roomRepository;
  roomRepository.Add(r3);
  Room* r4 = new Room("Sala 420");
  roomRepository.Add(r4);

  std::vector<Room*> rooms = roomRepository.GetAll();
  for(int i = 0; i < (int)rooms.size(); ++i) {
    std::cout << rooms[i]->GetName() << std::endl;
  }

  roomRepository.Remove(r3);
  rooms = roomRepository.GetAll();

  for(int i = 0; i < (int)rooms.size(); ++i) {
    std::cout << " " << rooms[i]->GetName() << std::endl;
  }

  SubjectRepository subjectRepository;
  subjectRepository.Add(s);

  Subject* s10 = new Subject("French");
  subjectRepository.Add(s10);


  std::vector<Subject*> subjects = subjectRepository.GetAll();

  for(int i = 0; i < (int)subjects.size(); ++i) {
    std::cout << subjects[i]->GetName() << std::endl;
  }

  subjectRepository.Remove(s);

  subjects = subjectRepository.GetAll();

  for(int i = 0; i < (int)subjects.size(); ++i) {
    std::cout << subjects[i]->GetName() << std::endl;
  }

  // mai trebuie a verific odata
  ActivityRepository activity3;
  std::vector<Activity*> act1 = activity3.FindByLocation("Sala 420");

  for (int i = 0; i < (int)act1.size(); ++i) {
    std::cout << act1[i]->GetDescription() << std::endl;
  }

  ActivityRepository activity4;
  act1 = activity4.FindByOwner("Popescu");
  for (int i = 0; i < (int)act1.size(); ++i) {
    std::cout << act1[i]->GetDescription() << std::endl;
  }

  ActivityRepository activity5;
  act1 = activity5.FindByType(Activity::DIDACTIC);

  for (int i = 0; i < (int)act1.size(); ++i) {
    std::cout << act1[i]->GetDescription() << std::endl;
  }

  PersonRepository pr;
  Person * pp = new Teacher("Mariaa", "Serban", "maria@yahoo.com", 27374, "math", "lector");
  pr.Add(pp);
  std::cout << " ";
  std::cout << pr.FindByLastName("Serban")->GetFirstName() << std::endl;

  std::cout << pr.FindByFirstName("Mariaa")->GetEmail() << std::endl;

  std::cout << pr.FindByFullName("Serban", "Mariaa")->GetCnp() << std::endl;

  std::cout << pr.FindByCnp(27374)->GetFirstName() << std::endl;

  std::cout << pr.FindByEmail("maria@yahoo.com")->GetFirstName() << std::endl;

  std::vector<Person*> person = pr.FindByType(Teacher::TEACHER);

  for (int i = 0; i < (int)person.size(); ++i) {
    std::cout << person[i]->GetCnp() << std::endl;
  }

  std::cout << "----------------------------------\n";

  StudentRecord record;
  record.Add(new Student("ion", "john", "a@a.com", 8271928, 122, 2, 12));
  record.Add(new Student("iion", "jjohn", "aa@a.com", 8271927, 123, 2, 13));

  didacticActivity = DidacticActivity(&teacher3, &room, "aaa", &subject);
  didacticActivity.AddParticipant(record.FindById(122));
  didacticActivity.AddParticipant(record.FindByEmail("aa@a.com"));

  std::vector<int> grds; grds.push_back(9); grds.push_back(10);
  record.GradeActivity(&didacticActivity, grds);
  record.GradeActivity(&didacticActivity, grds);

  std::cout << record;

  return 0;
}





























