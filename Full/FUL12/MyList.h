#pragma once

#include <initializer_list>

#include "MyNode.h"

class MyList
{
public:
  MyList();
  MyList(unsigned size);
  MyList(std::initializer_list<int> list);
  MyList(const MyList& other);
  MyList(MyList&& other);
  MyList(int (*function)(MyNode*), int size);

  void clear();
  void add(int element);
  bool empty() const;
  unsigned size() const;
  void print() const;

  ~MyList();
private:
  MyNode* _head = nullptr;
  MyNode* _tail = nullptr;
  unsigned _size = 0;
};
