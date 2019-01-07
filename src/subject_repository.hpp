#ifndef SUBJECT_REPOSITORY_HPP
#define SUBJECT_REPOSITORY_HPP

#include "subject.hpp"
#include "repository.hpp"

class SubjectRepository : public Repository<Subject> {
 public:
  Subject* FindByName(const std::string& name);
};

#endif