#ifndef ADMNINISTRATIVE_ACTIVITY_HPP
#define ADMNINISTRATIVE_ACTIVITY_HPP

#include "activity.hpp"
#include "administrative.hpp"

class AdministrativeActivity : public Activity {
 public:
  AdministrativeActivity(Administrative* owner, Room* room,
    const std::string& name, const std::string& description);

  Type GetType();
 protected:
  bool ValidateOwner(Person* owner);
  bool ValidateParticipant(Person* participant);
};

#endif
