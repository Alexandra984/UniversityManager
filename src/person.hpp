#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
 public:
  enum Type {
    STUDENT,
    TEACHER,
    ADMINISTRATIVE
  };
  virtual ~Person();
  Person(const std::string& first_name, const std::string& last_name,
    const std::string& email, int cnp);

  std::string GetFirstName();
  std::string GetLastName();
  std::string GetEmail();
  int GetCnp();

  void SetFirstName(const std::string& first_name);
  void SetLastName(const std::string& last_name);
  void SetEmail(const std::string& email);
  void SetCnp(int cnp);

  virtual Type GetType() = 0;
 protected:
  std::string _first_name;
  std::string _last_name;
  std::string _email;
  int _cnp;
};

#endif
