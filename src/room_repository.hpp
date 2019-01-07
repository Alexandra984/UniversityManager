#ifndef ROOM_REPOSITORY_HPP
#define ROOM_REPOSITORY_HPP

#include "repository.hpp"
#include "room.hpp"

class RoomRepository : public Repository<Room> {
 public:
  Room* FindByName(const std::string& name);
};

#endif