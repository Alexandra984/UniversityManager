#ifndef GRADE_LIST_HPP
#define GRADE_LIST_HPP

#include "subject.hpp"
#include <vector>

class GradeList {
 public:
  virtual ~GradeList();
  GradeList(Subject* subject);

  Subject* GetSubject();
  std::vector<int> GetGrades();

  void AddGrade(int grade);
 private:
  Subject* _subject;
  std::vector<int> _grades;
};

#endif
