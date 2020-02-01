#pragma once

#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include <vector>
#include <list>
#include <climits>

#define DEFAULT_CAP 50;
#define CAPACITY_MULTIPLIER 2

#define KNUTH_CONSTANT (2654435761 % LONG_MAX)

#define TEMPLATE_T template<typename T>

TEMPLATE_T
class hashmap 
{
private:
  int size_;
  int capacity_;
  std::vector<std::list<T>> table_;

  int hash(int key);

public:
  hashmap();
  hashmap(int capacity);

  void insert(int key, T el);
  bool contains(int key);
  void remove(int key);
};

TEMPLATE_T
hashmap<T>::hashmap()
  : size_(0), capacity_(DEFAULT_CAP)
{
  table_.resize(capacity_, list<T>());
}

TEMPLATE_T
hashmap<T>::hashmap(int capacity)
  : size_(0), capacity_(capacity)
{
  table_.resize(capacity_, list<T>());
}


// knuth's multiplicative method
TEMPLATE_T
int
hashmap<T>::hash(int key)
{
  return (key * KNUTH_CONSTANT) % capacity_;
}

TEMPLATE_T
void 
hashmap<T>::insert(int key, T el) 
{
  int pos = hash(key);
  table_[pos].push_back(el);
  ++size_;
  
  if (size > capacity_) {
    capacity_ *= CAPACITY_MULTIPLIER;
    table_.resize(capacity_);
  }
}

TEMPLATE_T
bool
hashmap<T>::contains(int key)
{
  int pos = hash(key);

  return (table_[pos].size() != 0);
}

TEMPLATE_T
void
hashmap<T>::remove(int key)
{
  int pos = hash(key);
  if (table_[pos].size() == 0) return;

  table_[pos].pop_front();
  --size_;
}

#endif /* _HASH_TABLE_HPP_ */