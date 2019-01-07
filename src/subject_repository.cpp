#include <iostream>
#include "subject_repository.cpp"

Subject* SubjectRepository::FindByName(const std::string& name) {
  for (int i = 0; i < (int)_entities.size(), ++i) {
    if (_entities[i]->GetName() == name)
      return _entities[i];
    else
      std::cout << "This subject doesn't exist" << std::endl;
  }
  exit(1);
}
