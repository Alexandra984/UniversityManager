#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "person.hpp"

class Teacher : public Person {
 public:
  Teacher(const std::string& first_name, const std::string& last_name,
    const std::string& email, long long cnp, const std::string& studies,
    const std::string& function);

  std::string GetStudies();
  std::string GetFunction();

  void SetStudies(const std::string& studies);
  void SetFunction(const std::string& function);

  Type GetType();
 protected:
  void PrintAdditional(std::ostream& out);
 private:
  std::string _studies;
  std::string _function;
};

#endif
