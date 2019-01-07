#include <iostream>
#include <cstdlib>
#include "person_repository.hpp"

Person* PersonRepository::FindByLastName(const std::string& last_name) {
  for (int i = 0; i <(int) _entities.size(); ++i) {
    if (_entities[i]->GetLastName() == last_name) {
      return _entities[i];
    }
  }
  exit(1);
}

Person* PersonRepository::FindByFirstName(const std::string& first_name) {
  for (int i = 0; i <(int) _entities.size(); ++i) {
    if (_entities[i]->GetFirstName() == first_name) {
      return _entities[i];
    }
  }
  exit(1);
}

Person* PersonRepository::FindByFullName(const std::string& last_name,
    const std::string& first_name) {
  for (int i = 0; i <(int) _entities.size(); ++i) {
    if (_entities[i]->GetLastName() == last_name && _entities[i]->GetFirstName()
        == first_name) {
      return _entities[i];
    }
  }
  exit(1);
}

Person* PersonRepository::FindByCnp(int cnp) {
  for (int i = 0; i <(int) _entities.size(); ++i) {
    if (_entities[i]->GetCnp() == cnp) {
      return _entities[i];
    }
  }
  exit(1);
}

Person* PersonRepository::FindByEmail(const std::string& email) {
  for (int i = 0; i <(int) _entities.size(); ++i) {
    if (_entities[i]->GetEmail() == email) {
      return _entities[i];
    }
  }
  exit(1);
}

std::vector<Person*> PersonRepository::FindByType(Person::Type type) {
  std::vector<Person*> people;
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetType() == type) {
      people.push_back(_entities[i]);
    }
  }
  return people;
}
