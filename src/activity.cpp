#include <iostream>
#include "activity.hpp"

Activity::~Activity() {};

Activity::Activity(Person* owner, Room* room, const std::string& name,
    const std::string& description) :
  _owner(owner),
  _room(room),
  _name(name),
  _description(description) {
}

Person* Activity::GetOwner() {
  return _owner;
}

Room* Activity::GetRoom() {
  return _room;
}

std::string Activity::GetName() {
  return _name;
}

std::string Activity::GetDescription() {
  return _description;
}

std::vector<Person*> Activity::GetParticipants() {
  return _participants;
}

void Activity::SetOwner(Person* owner) {
  if (ValidateOwner(owner))
    _owner = owner;
  else
    return;
}

void Activity::SetRoom(Room* room) {
  _room = room;
}

void Activity::SetDescription(const std::string& description) {
  _description = description;
}

void Activity::AddParticipant(Person* participant) {
  if (ValidateParticipant(participant))
    _participants.push_back(participant);
  else
    return;
}
