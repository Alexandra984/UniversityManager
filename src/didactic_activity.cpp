#include <iostream>
#include "didactic_activity.hpp"

DidacticActivity::DidacticActivity(Teacher* owner, Room* room,
    const std::string& name, const std::string& description, Subject* subject) :
  Activity(owner, room, name, description),
  _subject(subject) {
}

Subject* DidacticActivity::GetSubject() {
  return _subject;
}

void DidacticActivity::SetSubject(Subject* subject) {
  _subject = subject;
}

Activity::Type DidacticActivity::GetType() {
  return DIDACTIC;
}

bool DidacticActivity::ValidateOwner(Person* owner) {
  if (owner->GetType() == Person::TEACHER)
    return true;
  else
    std::cout << "This is not the right person" << std::endl;
    return false;
}

bool DidacticActivity::ValidateParticipant(Person* participant) {
  if (participant->GetType() == Person::STUDENT)
    return true;
  else
    return false;
}
