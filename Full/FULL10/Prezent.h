#pragma once

class Worek;

/// Klasa reprezentująca prezent. Zawiera wartość prezentu i wskaźnik na następny prezent w liście.
class Prezent
{
  //Przyjaźń z klasą będącą listą obiektów Prezent;
  friend Worek;
public:
  /** Konstruktor, przyjmuje i ustawia wartość prezentu.
  * @param value wartość prezentu
  */
  Prezent(float value);

  ///Wypisuje informacje o prezencie;
  void Wypisz() const;

private:
  ///Wartość prezentu
  float _value;
  ///Wskaźnik na następny prezent w liście
  Prezent* _next = nullptr;
};
