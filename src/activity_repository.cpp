#include <iostream>
#include "activity_repository.hpp"

std::vector<Activity*> ActivityRepository::FindByLocation(const std::string& room_name) {
  std::vector<Activity*> activities;
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if ((_entities[i]->GetRoom())->GetName() == room_name) {
      activities.push_back(_entities[i]);
    }
  }
  return activities;
}

std::vector<Activity*> ActivityRepository::FindByOwner(const std::string& owner_name) {
  std::vector<Activity*> activities;
  for (int i = 0; i < (int)_entities.size(); ++i) {
    if ((_entities[i]->GetOwner())->GetLastName() == owner_name)
      activities.push_back(_entities[i]);
  }
  return activities;
}

std::vector<Activity*> ActivityRepository::FindByType(Activity::Type type) {
  std::vector<Activity*> activities;
  for (int i = 0; i < (int)_entities.size(); ++i) {
     if ((_entities[i]->GetType()) == type)
      activities.push_back(_entities[i]);
  }
  return activities;
}

Activity* ActivityRepository::FindByName(const std::string& name) {
  for (int i = 0; i < (int)_entities.size(); ++i) {
     if (_entities[i]->GetName() == name)
      return _entities[i];
  }
  return NULL;
}

