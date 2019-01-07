#ifndef ACTIVITY_REPOSITORY_HPP
#define ACTIVITY_REPOSITORY_HPP

#include "repository.hpp"
#include "activity.hpp"

class ActivityRepository : public Repository<Activity> {
 public:
  std::vector<Activity*> FindByLocation(const std::string& room_name);
  std::vector<Activity*> FindByOwner(const std::string& owner_name);
  std::vector<Activity*> FindByType(Activity::Type type);
};

#endif
