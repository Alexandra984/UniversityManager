#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <string>

class Subject {
 public:
  virtual ~Subject();
  Subject(const std::string& name);

  std::string GetName();
  void SetName(const std::string& name);
 private:
  std::string _name;
};

#endif
