#ifndef DIDACTIC_ACTIVITY_HPP
#define DIDACTIC_ACTIVITY_HPP

#include "activity.hpp"
#include "teacher.hpp"
#include "subject.hpp"

class DidacticActivity : public Activity {
 public:
  DidacticActivity(Teacher* owner, Room* room, const std::string& name,
    const std::string& description, Subject* subject);

  Subject* GetSubject();
  void SetSubject(Subject* subject);

  Type GetType();
 protected:
  bool ValidateOwner(Person* owner);
  bool ValidateParticipant(Person* participant);
 private:
  Subject* _subject;
};

#endif
