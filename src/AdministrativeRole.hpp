#ifndef UNIVERSITYMANAGER_SRC_ADMINISTRATIVEROLE_HPP_
#define UNIVERSITYMANAGER_SRC_ADMINISTRATIVEROLE_HPP_

#include "Role.hpp"

class AdministrativeRole : public Role {
public:
  virtual RoleType getType();
};

#endif
