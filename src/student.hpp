#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

class Student : public Person {
 public:
  Student(const std::string& first_name, const std::string& last_name,
    const std::string& email, long long cnp, int id, int year, int group_no);

  int GetId();
  int GetYear();
  int GetGroupNo();

  void SetId(int id);
  void SetYear(int year);
  void SetGroupNo(int group_no);

  Type GetType();

 protected:
  void PrintAdditional(std::ostream& out);

 private:
  int _id;
  int _year;
  int _group_no;
};

#endif
