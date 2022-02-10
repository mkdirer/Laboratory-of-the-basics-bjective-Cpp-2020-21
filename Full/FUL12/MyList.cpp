#include <iostream>
#include <utility>

#include "MyList.h"

MyList::MyList()
{
  std::cout<<"KONST: Domyslny"<<std::endl;
}

MyList::MyList(unsigned size)
: MyList()
{
  std::cout<<"KONST: Jednoargumentowy"<<std::endl;  
  for(unsigned a = 0; a < size; a++)
  {
    add(a);
  }
}

MyList::MyList(std::initializer_list<int> list)
{
  std::cout<<"KONST: std::initializer_list"<<std::endl;

  std::initializer_list<int>::iterator next = list.begin();
  while(next != list.end())
  {
    add(*next);
    next++;
  }
}

MyList::MyList(const MyList& other)
: MyList()
{
  std::cout<<"KONST: kopiujacy"<<std::endl;

  MyNode* next = other._head;
  while(next != nullptr)
  {
    add(next->val());
    next = next->getNext();
  }
}

MyList::MyList(MyList&& other)
: _head(std::exchange(other._head, nullptr))
, _tail(std::exchange(other._tail, nullptr))
, _size(std::exchange(other._size, 0))
{
  std::cout<<"KONST: przenoszacy"<<std::endl;
}

MyList::MyList(int (*function)(MyNode*), int size)
{
  std::cout<<"KONST: funkcja generujaca"<<std::endl;

  for(unsigned a = 0; a < size; a++)
  {
    add(function(_tail));
  }
}

void MyList::clear()
{
  MyNode* next = _head;
  while(next != nullptr)
  {
    MyNode* temp = next->getNext();
    delete next;
    next = temp;
  }
  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}

void MyList::add(int element)
{
  if(_tail == nullptr)
  {
    _head = new MyNode(element);
    _tail = _head;
  }
  else
  {
    _tail->setNext(new MyNode(element));
    _tail = _tail->getNext();
  }
  _size++;
}

bool MyList::empty() const
{
  return _size == 0;
}

unsigned MyList::size() const
{
  return _size;
}

void MyList::print() const
{
  if(_size == 0)
  {
    std::cout<<"[]"<<std::endl;
    return;
  }

  std::cout<<"["<<_head->val();
  MyNode* next = _head->getNext();
  while(next != nullptr)
  {
    std::cout<<", "<<next->val();
    next = next->getNext();
  }
  std::cout<<"]"<<std::endl;
}

MyList::~MyList()
{
  std::cout<<"DESTRUKTOR (rozmiar = "<<_size<<")"<<std::endl;
  clear();
}
