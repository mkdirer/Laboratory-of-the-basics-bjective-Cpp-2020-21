#include "Prezent.h"

#include <iostream>

Prezent::Prezent(float value)
: _value(value) {}

void Prezent::Wypisz() const
{
  std::cout<<"Prezent o wartosci: "<<_value<<std::endl;
}
