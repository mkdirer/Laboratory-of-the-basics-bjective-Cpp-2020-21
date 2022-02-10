#include "Worek.h"

#include <iostream>

Worek::Worek() {}

Worek::Worek(const Worek& other)
{
  _first = new Prezent(*other._first);
  _last = _first;
  Prezent* next = other._first;
  while(next->_next != nullptr)
  {
    Wloz(*next->_next);
    next = next->_next;
  }
}

void Worek::Wloz(const Prezent& gift)
{
  Prezent* giftCopy = new Prezent(gift);
  if(_last == nullptr)
  {
    _last = giftCopy;
    _first = giftCopy;
  }
  else
  {
    _last->_next = giftCopy;
    _last = giftCopy;
  }
}

void Worek::WypiszZawartosc() const
{
  std::cout<<"=== Zawartosc worka ==="<<std::endl;
  Prezent* next = _first;
  unsigned giftNumber = 1;
  while(next != nullptr)
  {
    std::cout<<giftNumber<<". ";
    next->Wypisz();
    giftNumber++;
    next = next->_next;
  }
}

void Worek::UsunPrezentNumer(unsigned number)
{
  Prezent* previous = nullptr;
  Prezent* next = _first;
  unsigned giftNumber = 1;
  while(next != nullptr)
  {
    if(giftNumber == number)
    {
      if(previous == nullptr)
      {
        _first = next->_next;
      }
      else
      {
        previous->_next = next->_next;
      }

      if(next == _last)
      {
        _last = previous;
      }

      delete next;
      break;
    }

    giftNumber++;
    previous = next;
    next = next->_next;
  }
}

Worek::~Worek()
{
  Prezent* next = _first;
  Prezent* temp;
  while(next != nullptr)
  {
    temp = next->_next;
    delete next;
    next = temp;
  }
}




/*
#include <iostream>
#include "Prezent.h"
#include "Worek.h"

void UkradnijPrezenty (Worek worekZPrezentami)
{
  std::cout<<"Kradne prezenty 3 i 1\n";

  worekZPrezentami.UsunPrezentNumer(3);
  worekZPrezentami.UsunPrezentNumer(1);

  worekZPrezentami.WypiszZawartosc();
}

int main(){
  // UWAGA!!!
  // Do rozwiazania zadania nie wolno uzywac tablic ani wektorow. Uzycie
  // niedozwolonej struktury oznacza 0 punktow.
    
  const float wartoscCzapki = 100;
  Prezent czapka (wartoscCzapki);
  Prezent skarpety (35);
  skarpety.Wypisz();
  Prezent wypasionaCzapka (200);
  Prezent szalik (55);

  Worek worekZPrezentami;
  worekZPrezentami.Wloz(skarpety);
  worekZPrezentami.Wloz(szalik);
  worekZPrezentami.Wloz(czapka);
  worekZPrezentami.Wloz(szalik);
  worekZPrezentami.Wloz(wypasionaCzapka);

  worekZPrezentami.WypiszZawartosc();

  worekZPrezentami.UsunPrezentNumer(5);
  worekZPrezentami.UsunPrezentNumer(2);
  worekZPrezentami.WypiszZawartosc();

  UkradnijPrezenty (worekZPrezentami);
  
  std::cout<<"Na szczescie nic nie zginelo.\n";

  worekZPrezentami.WypiszZawartosc();
  
  return 0;
}
*/

/* output:
Prezent o wartosci: 35
=== Zawartosc worka ===
1. Prezent o wartosci: 35
2. Prezent o wartosci: 55
3. Prezent o wartosci: 100
4. Prezent o wartosci: 55
5. Prezent o wartosci: 200
=== Zawartosc worka ===
1. Prezent o wartosci: 35
2. Prezent o wartosci: 100
3. Prezent o wartosci: 55
Kradne prezenty 3 i 1
=== Zawartosc worka ===
1. Prezent o wartosci: 100
Na szczescie nic nie zginelo.
=== Zawartosc worka ===
1. Prezent o wartosci: 35
2. Prezent o wartosci: 100
3. Prezent o wartosci: 55
*/