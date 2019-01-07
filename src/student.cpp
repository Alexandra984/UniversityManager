#include <iostream>
#include "student.hpp"

Student:: Student(const std::string& first_name, const std::string& last_name,
    const std::string& email, long long cnp, int id, int year, int group_no) :
  Person::Person(first_name, last_name, email, cnp),
  _id(id),
  _year(year),
  _group_no(group_no) {
  }

int Student::GetId() {
  return _id;
}

int Student::GetYear() {
  return _year;
}

int Student::GetGroupNo() {
  return _group_no;
}

void Student::SetId(int id) {
  _id = id;
}

void Student::SetYear(int year) {
  _year = year;
}

void Student::SetGroupNo(int group_no) {
  _group_no = group_no;
}

Student::Type Student::GetType() {
  return STUDENT;
}

void Student::PrintAdditional(std::ostream& out) {
  out << "Id: " << _id << '\n';
  out << "Year: " << _year << '\n';
  out << "Group: " << _group_no << '\n';
}
