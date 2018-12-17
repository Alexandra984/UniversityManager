#ifndef UNIVERSITYMANAGER_SRC_ROLE_HPP_
#define UNIVERSITYMANAGER_SRC_ROLE_HPP_

#include <iostream>

class Role {
public:
  enum RoleType {
    ADMINISTRATIVE,
    STUDENT,
    TEACHER,
    GUEST
  };

  virtual ~Role();

  virtual RoleType getType() = 0;
};

#endif
