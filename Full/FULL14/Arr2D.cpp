#include "Arr2D.h"

Arr2D::Arr2D(unsigned sizeX, unsigned sizeY)
: ownsMemory(true)
, _sizeX(sizeX)
, _sizeY(sizeY)
{
  _data = new int[sizeX * sizeY];
  for(unsigned a = 0; a < _sizeX * _sizeY; a++)
  {
    _data[a] = 0;
  }
}

Arr2D Arr2D::adopt(int* data, unsigned sizeX, unsigned sizeY)
{
  Arr2D array;
  array._data = data;
  array.ownsMemory = false;
  array._sizeX = sizeX;
  array._sizeY = sizeY;
  return array;
}

int* Arr2D:: operator[](unsigned index)
{
  return &_data[index * _sizeX];
}

int* Arr2D:: operator[](unsigned index) const
{
  return &_data[index * _sizeX];
}

void operator<<=(const char* string, const Arr2D& data)
{
  std::cout<<string<<std::endl;
  if(data._sizeX == 0) return;

  for(unsigned y = 0; y < data._sizeY; y++)
  {
    std::cout<<data[y][0];
    for(unsigned x = 1; x < data._sizeX; x++)
    {
      std::cout<<" "<<data[y][x];
    }
    std::cout<<std::endl;
  }
}

Arr2D::~Arr2D()
{
  if(ownsMemory && _data != nullptr)
  {
    delete[] _data;
    _sizeX = 0;
    _sizeY = 0;
  }
}