#ifndef UNIVERSITYMANAGER_SRC_GUESTROLE_HPP_
#define UNIVERSITYMANAGER_SRC_GUESTROLE_HPP_

#include "Role.hpp"

class GuestRole : public Role {
public:
  virtual RoleType getType();
};

#endif
