#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <vector>
#include <string>
#include "person.hpp"
#include "room.hpp"

class Activity {
 public:
  enum Type {
    DIDACTIC,
    ADMINISTRATIVE
  };

  virtual ~Activity();
  Activity(Person* owner, Room* room, const std::string& name,
    const std::string& description);

  Person* GetOwner();
  Room* GetRoom();
  std::string GetName();
  std::string GetDescription();
  std::vector<Person*> GetParticipants();

  void SetOwner(Person* owner);
  void SetRoom(Room* room);
  void SetDescription(const std::string& description);
  void AddParticipant(Person* participant);

  virtual Type GetType() = 0;
 protected:
  virtual bool ValidateOwner(Person* owner) = 0;
  virtual bool ValidateParticipant(Person* participant) = 0;

  Person* _owner;
  Room* _room;
  std::string _name, _description;
  std::vector<Person*> _participants;
};

#endif
