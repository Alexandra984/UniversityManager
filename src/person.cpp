#include "person.hpp"
#include <iostream>

Person::~Person() {}

Person:: Person(const std::string& first_name, const std::string& last_name,
    const std::string& email, long long cnp) :
  _first_name(first_name),
  _last_name(last_name),
  _email(email),
  _cnp(cnp) {
  }

std::string Person::GetFirstName() {
  return _first_name;
}

std::string Person::GetLastName() {
  return _last_name;
}

std::string Person::GetEmail() {
  return _email;
}

int Person::GetCnp() {
  return _cnp;
}

void Person::SetFirstName(const std::string& first_name) {
  _first_name = first_name;
}

void Person::SetLastName(const std::string& last_name) {
  _last_name = last_name;
}

void Person::SetEmail(const std::string& email) {
  _email = email;
}

void Person::SetCnp(int cnp) {
  _cnp = cnp;
}

std::ostream& operator<<(std::ostream& out, Person& person) {
  out << person._first_name << ' ' << person._last_name << '\n';
  out << "Email: " << person._email << '\n';
  out << "CNP: " << person._cnp << '\n';
  person.PrintAdditional(out);
  return out;
}
