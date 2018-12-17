#ifndef UNIVERSITYMANAGER_SRC_STUDENTROLE_HPP_
#define UNIVERSITYMANAGER_SRC_STUDENTROLE_HPP_

#include "Role.hpp"

class StudentRole : public Role {
public:
  virtual RoleType getType();
};

#endif
