#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>

class Person {
 public:
  enum Type {
    STUDENT,
    TEACHER,
    ADMINISTRATIVE
  };
  virtual ~Person();
  Person(const std::string& first_name, const std::string& last_name,
    const std::string& email, long long cnp);

  std::string GetFirstName();
  std::string GetLastName();
  std::string GetEmail();
  int GetCnp();

  void SetFirstName(const std::string& first_name);
  void SetLastName(const std::string& last_name);
  void SetEmail(const std::string& email);
  void SetCnp(int cnp);

  virtual Type GetType() = 0;

  friend std::ostream& operator<<(std::ostream& out, Person& person);
 protected:
  virtual void PrintAdditional(std::ostream& out) = 0;

  std::string _first_name;
  std::string _last_name;
  std::string _email;
  long long _cnp;
};

#endif
