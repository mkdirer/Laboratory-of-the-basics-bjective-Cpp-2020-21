#pragma once

double abs(const double& data);

class MapDistance  
{
  private:
  double latidiff;
  double longidiff;
  public:

  /** ustawia szerokosc i dlugosc geograficzna punktu na podstawie argumentow, ktore przyjmuje.
  *@param latit, szerokosc geograficzna
  *@param longit, długosc geograficzna
  */
  void set_coordinates(const double& latid, const double& longid);

  /**wypisuje na ekran, ze jest to punkt i podaje jego wspolrzedne w nawiasach okraglych.
  d*/
  void print();
};