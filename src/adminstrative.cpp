#include <iostream>
#include "administrative.hpp"

Administrative::Administrative(const std::string& first_name, const std::string& last_name,
    const std::string& email, int cnp) :
  Person(first_name, last_name, email, cnp) {
}

Administrative::Type Administrative::GetType() {
  return ADMINISTRATIVE;
}
