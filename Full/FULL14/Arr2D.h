#pragma once

#include <initializer_list>
#include <iostream>

class Arr2D
{
  friend void operator<<=(const char* string, const Arr2D& data);
public:
  Arr2D() = default;
  Arr2D(unsigned sizeX, unsigned sizeY);
  static Arr2D adopt(int* data, unsigned sizeX, unsigned sizeY);

  int* operator[](unsigned index);
  int* operator[](unsigned index) const;

  ~Arr2D();

private:
  int* _data = nullptr;
  bool ownsMemory;
  unsigned _sizeX;
  unsigned _sizeY;
};

void operator<<=(const char* string, const Arr2D& data);
