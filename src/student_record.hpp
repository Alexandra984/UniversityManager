#ifndef STUDENT_RECORD_HPP
#define STUDENT_RECORD_HPP

#include "student.hpp"
#include "repository.hpp"
#include "grade_list.hpp"
#include "didactic_activity.hpp"
#include <map>

class StudentRecord : public Repository<Student> {
 public:
  Student* FindByLastName(const std::string& last_name);
  Student* FindByFirstName(const std::string& first_name);
  Student* FindByFullName(const std::string& last_name,
      const std::string& first_name);
  Student* FindByCnp(int cnp);
  Student* FindByEmail(const std::string& email);
  Student* FindById(int id);
  std::vector<Student*> FindByGroupNo(int group_no);
  std::vector<Student*> FindByYear(int year);

  void AddSubjectToStudent(Student* student, Subject* subject);
  void AddGradeToStudent(Student* student, Subject* subject, int grade);
  bool HasStudentSubject(Student* student, Subject* subject);
  void GradeActivity(DidacticActivity* activity, const std::vector<int>& grades);

  std::vector<GradeList> GetStudentGrades(Student* student);
  GradeList GetStudentGradesForSubject(Student* student, Subject* subject);

  friend std::ostream& operator<<(std::ostream& out,
    StudentRecord& student_record);
 private:
  std::map<Student*, std::vector<GradeList> > _grades;
};

#endif
