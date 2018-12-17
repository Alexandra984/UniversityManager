#ifndef UNIVERSITYMANAGER_SRC_TEACHERROLE_HPP_
#define UNIVERSITYMANAGER_SRC_TEACHERROLE_HPP_

#include "Role.hpp"

class TeacherRole : public Role {
public:
  virtual RoleType getType();
};

#endif
