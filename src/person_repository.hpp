#ifndef PERSON_REPOSITORY_HPP
#define PERSON_REPOSITORY_HPP

#include "person.hpp"
#include "repository.hpp"

class PersonRepository : public Repository<Person> {
 public:
  Person* FindByLastName(const std::string& last_name);
  Person* FindByFirstName(const std::string& first_name);
  Person* FindByFullName(const std::string& last_name, 
    const std::string& first_name);
  Person* FindByCnp(int cnp);
  Person* FindByEmail(const std::string& email);
  std::vector<Person*> FindByType(Person::Type type);
};

#endif