#include "room.hpp"
#include <iostream>
#include <string>

Room::~Room() {};

Room::Room(const std::string& name) :
  _name(name) {
}

std::string Room::GetName() {
  return _name;
}

void Room::SetName(const std::string& name) {
  _name = name;
}
