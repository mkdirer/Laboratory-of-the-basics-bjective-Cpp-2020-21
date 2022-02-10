#pragma once

#include "Prezent.h"

///Klasa opakowująca listę linkowaną, jednokierunkową z obiektami klasy Prezent.
class Worek
{
public:
  //Konstruktor domyślny, identyczny z niejawnym.
  Worek();
  /** Konstruktor kopiujący. Tworzy głęboką kopię obiektu other.
  * @param other kopiowany obiekt Worek
  */
  Worek(const Worek& other);

  /** Umieszcza kopię obiektu gift, klasy Prezent, na końcu listy.
  * @param gift obiekt, którego kopia ma zostać umieszczona na końcu listy
  */
  void Wloz(const Prezent& gift);

  ///Wypisuje informacje o wszystkich prezentach na liście i ich numery.
  void WypiszZawartosc() const;
  
  /** Usuwa prezent o numerze number z listy i z pamięci.
  * @param number numer (indeks + 1) obiektu Prezent do usunięcia z listy i z pamięci
  */
  void UsunPrezentNumer(unsigned number);

  //Destruktor. Usuwa z pamięci wszystkie prezenty na liście.
  ~Worek();

private:
  Prezent* _first = nullptr;
  Prezent* _last = nullptr;
};
