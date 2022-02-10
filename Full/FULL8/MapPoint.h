#pragma once

class MapPoint
{
  private:
  double longitude;
  double latitude;
  public:

  /** ustawia szerokosc i dlugosc geograficzna punktu na podstawie argumentow, ktore przyjmuje.
  *@param latit, szerokosc geograficzna
  *@param longit, długosc geograficzna
  */
  void set_coordinates(const double& latit, const double& longit);

  /**wypisuje na ekran, ze jest to punkt i podaje jego wspolrzedne w nawiasach okraglych.
  d*/
  void print();

  /**zwraca obiekt typu MapDistance, ktory przechowuje informacje o roznicy pomiedzy dlugosciami geograficznymi dwoch punktow oraz roznicy pomiedzy szerokosciami geograficznymi tych samych punktow
  *@param point, punkt o danych parametrach
  *@return kalsa jako różnica geograficzna
  */
  MapDistance distance(const MapPoint& point);

  MapPoint half_way_to(const MapPoint point);
};
