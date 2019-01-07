#include "room_repository.hpp"
#include <iostream>
#include <cstdlib>

Room* RoomRepository::FindByName(const std::string& name) {
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if (_entities[i]->GetName() == name)
      return _entities[i];
  }
  std::cout << "No such room" << std::endl;
  exit(1);
}
