#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <vector>
#include <iostream>

template<typename T>
class Repository {
 public:
  virtual ~Repository();
  void Add(T* entity);
  void Remove(T* entity);
  int size();
  std::vector<T*> GetAll();
 protected:
  std::vector<T*> _entities;
};

template<typename T>
Repository<T>::~Repository() {
  for( int i = 0; i <(int)_entities.size(); ++i)
    delete _entities[i];
}

template<typename T>
void Repository<T>::Add(T* entity) {
  _entities.push_back(entity);
}

template<typename T>
void Repository<T>::Remove(T * entity) {
  for (int i = 0; i < (int)_entities.size(); ++i)
    if (_entities[i] == entity) {
      delete _entities[i];
      T* temp = _entities[i];
      _entities[i] = _entities[(int)_entities.size() - 1];
      _entities[(int)_entities.size() - 1] = temp;
      _entities.pop_back();
    }
}

template<typename T>
int Repository<T>::size() {
  return (int)_entities.size();
}

template<typename T>
std::vector<T*> Repository<T>::GetAll() {
  return _entities;
}

#endif
