#include <iostream>
#include "grade_list.hpp"

GradeList::~GradeList() {}

GradeList::GradeList(Subject* subject) :
  _subject(subject){
}

std::vector<int> GradeList::GetGrades() {
  return _grades;
}

Subject* GradeList::GetSubject() {
  return _subject;
}

void GradeList::AddGrade(int grade) {
  _grades.push_back(grade);
}

