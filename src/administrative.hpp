#ifndef ADMINISTRATIVE_HPP
#define ADMINISTRATIVE_HPP

#include "person.hpp"

class Administrative : public Person {
 public:
  Administrative(const std::string& first_name, const std::string& last_name,
    const std::string& email, long long cnp);

  Type GetType();
 protected:
  void PrintAdditional(std::ostream& out);
};

#endif
