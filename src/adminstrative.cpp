#include <iostream>
#include "administrative.hpp"

Administrative::Administrative(const std::string& first_name, const std::string& last_name,
    const std::string& email, long long cnp) :
  Person(first_name, last_name, email, cnp) {
}

Administrative::Type Administrative::GetType() {
  return ADMINISTRATIVE;
}

void Administrative::PrintAdditional(std::ostream& out) {
  out << "";
}
