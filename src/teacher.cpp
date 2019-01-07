#include <iostream>
#include "teacher.hpp"

Teacher::Teacher(const std::string& first_name, const std::string& last_name,
    const std::string& email, int cnp, const std::string& studies,
    const std::string& function) :
  Person(first_name, last_name, email, cnp),
  _studies(studies),
  _function(function) {
}

std::string Teacher::GetStudies() {
  return _studies;
}

std::string Teacher::GetFunction() {
  return _function;
}

void Teacher::SetStudies(const std::string& studies) {
  _studies = studies;
}

void Teacher::SetFunction(const std::string& function) {
  _function = function;
}

Teacher::Type Teacher::GetType() {
  return TEACHER;
}

