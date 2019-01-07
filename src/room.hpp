#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room {
 public:
  virtual ~Room();
  Room(const std::string& name);
  std::string GetName();
  void SetName(const std::string& name);
 private:
  std::string _name;
};

#endif
