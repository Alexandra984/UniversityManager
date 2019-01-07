#include <iostream>
#include "subject.hpp"

Subject::~Subject() {};

Subject::Subject(const std::string& name) :
  _name(name) {
}

std::string Subject::GetName() {
  return _name;
}

void Subject::SetName(const std::string& name) {
  _name = name;
}
