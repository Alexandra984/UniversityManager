#include "student_record.hpp"
#include <iostream>

Student* StudentRecord::FindByLastName(const std::string& last_name) {
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetLastName() == last_name)
      return _entities[i];
  }
  return NULL;
}

Student* StudentRecord::FindByFirstName(const std::string& first_name) {
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetFirstName() == first_name)
      return _entities[i];
  }
  return NULL;
}

Student* StudentRecord::FindByFullName(const std::string& last_name, const std::string& first_name) {
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetLastName() == last_name && _entities[i]->GetFirstName() == first_name)
      return _entities[i];
  }
  return NULL;
}

Student* StudentRecord::FindByCnp(int cnp) {
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetCnp() == cnp)
      return _entities[i];
  }
  return NULL;
}

Student* StudentRecord::FindByEmail(const std::string& email) {
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetEmail() == email)
      return _entities[i];
  }
  return NULL;
}

Student* StudentRecord::FindById(int id) {
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetId() == id)
      return _entities[i];
  }
  return NULL;
}

std::vector<Student*> StudentRecord::FindByGroupNo(int group_no) {
  std::vector<Student*> people;
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetGroupNo() == group_no) {
      people.push_back(_entities[i]);
    }
  }
  return people;
}

std::vector<Student*> StudentRecord::FindByYear(int year) {
  std::vector<Student*> people;
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetYear() == year) {
      people.push_back(_entities[i]);
    }
  }
  return people;
}

void StudentRecord::AddSubjectToStudent(Student* student, Subject* subject) {
  for (int i = 0; i < (int)_grades[student].size(); ++i) {
    if (_grades[student][i].GetSubject() == subject) {
      return;
    }
  }
  _grades[student].push_back(GradeList(subject));
}

void StudentRecord::AddGradeToStudent(Student* student, Subject* subject, int grade) {
  for (int i = 0; i < (int)_grades[student].size(); ++i) {
    if (_grades[student][i].GetSubject() == subject) {
      _grades[student][i].AddGrade(grade);
      return;
    }
  }
}

bool StudentRecord::HasStudentSubject(Student* student, Subject* subject) {
  for (int i = 0; i < (int)_grades[student].size(); ++i) {
    if (_grades[student][i].GetSubject() == subject) {
      return true;
    }
  }
  return false;
}

void StudentRecord::GradeActivity(DidacticActivity* activity,
    const std::vector<int>& grades) {
  if (activity->GetType() != Activity::DIDACTIC)
    return;
  std::vector<Person*> participants = activity->GetParticipants();
  for (int i = 0; i < (int)participants.size(); ++i) {
    Student* student = static_cast<Student*>(participants[i]);
    AddSubjectToStudent(student, activity->GetSubject());
    AddGradeToStudent(student, activity->GetSubject(), grades[i]);
  }
}

std::vector<GradeList> StudentRecord::GetStudentGrades(Student* student) {
  return _grades[student];
}

GradeList StudentRecord::GetStudentGradesForSubject(Student* student, Subject* subject) {
  GradeList res = GradeList(subject);
  for (int i = 0; i < (int)_grades[student].size(); ++i) {
    if (_grades[student][i].GetSubject() == subject) {
      res = _grades[student][i];
      break;
    }
  }
  return res;
}

std::ostream& operator<<(std::ostream& out, StudentRecord& student_record) {
  std::map<Student*, std::vector<GradeList> >::iterator it;
  for (it = student_record._grades.begin(); it != student_record._grades.end(); ++it) {
    Student* student = it->first;
    out << student->GetLastName() << ' ' << student->GetFirstName() << '\n';
    for (int i = 0; i < (int)(it->second).size(); ++i) {
      out << (it->second)[i].GetSubject()->GetName() << ": ";
      std::vector<int> grades = (it->second)[i].GetGrades();
      for (int j = 0; j < (int)grades.size(); ++j) {
        out << grades[j] << ' ';
      }
      out << '\n';
    }
  }
  return out;
}
