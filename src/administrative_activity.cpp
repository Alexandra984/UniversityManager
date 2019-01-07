#include <iostream>
#include "administrative_activity.hpp"

AdministrativeActivity::AdministrativeActivity(Administrative* owner, Room* room,
    const std::string& name, const std::string& description) :
  Activity(owner, room, name, description) {
}

AdministrativeActivity::Type AdministrativeActivity::GetType() {
  return ADMINISTRATIVE;
}

bool AdministrativeActivity::ValidateOwner(Person* owner) {
  if (owner->GetType() == Person::ADMINISTRATIVE)
    return true;
  else
    return false;
}

bool AdministrativeActivity::ValidateParticipant(Person* participant) {
  if (participant->GetType() == Person::STUDENT)
    return true;
  else
    return false;
}
