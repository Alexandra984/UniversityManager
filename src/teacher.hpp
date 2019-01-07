#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "person.hpp"

class Teacher : public Person {
 public:
  Teacher(const std::string& first_name, const std::string& last_name, 
    const std::string& email, int cnp, const std::string& studies,
    const std::string& function);
  
  std::string GetStudies();
  std::string GetFunction();

  void SetStudies(const std::string& studies);
  void SetFunction(const std::string& function);

  Type GetType();
 private:
  std::string _studies;
  std::string _function;
};

#endif