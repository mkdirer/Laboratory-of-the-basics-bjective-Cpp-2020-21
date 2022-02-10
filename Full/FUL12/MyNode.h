#pragma once

class MyNode
{
public:
  MyNode(int value);

  MyNode* getNext() const;
  void setNext(MyNode* next);
  int val() const;

private:
  int _value;
  MyNode* _next = nullptr;
};
