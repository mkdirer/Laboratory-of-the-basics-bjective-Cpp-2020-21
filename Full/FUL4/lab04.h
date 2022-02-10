#pragma once
#include <iostream>

#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>

struct MapPoint{
	char name[20];
	double longitude;
	double latitude;
};

struct MapDist{
	double longitude;
	double latitude;
};

/** Funkcja tworzy nowy obiekt
@param nazwa dla nowego obiektu
@param dlugosc geograficzna
@param szerokosc geograficzna
@return wskaznik do nowo utworzonego obiektu
*/
MapPoint* construct(std::string nazwa, double y, double x);

/** Funkcja wyświetla nazwe oraz dlugosc i szerokosc geograficzna z podanego obiektu
@param miasto do wyswietlenia
*/
void print(MapPoint *city);

/** Funkcja wyznacza odleglosci na poszczegolnych osiach
@param pierwsze miasto
@param drugie miasto
@return obiekt w ktorym zapisane zostaja wyliczone roznice wspolrzednych
*/
MapDist distance(MapPoint *city_1, MapPoint city_2);

/** Funkcja oblicza odleglosc w lini prostej pomiedzy dwoma miastami na podstawie roznic wspolrzednych
@param obiekt zawierajacy roznice wspolrzednych
@return odleglosc w lini prostej
*/
double distanceMag(MapDist dane);

/** Funkcja tworzy nowy obiekt pomiedzy dwoma podanymi
@param pierwsze miasto
@param drugie miasto
@param nazwa dla nowego obiektu
@return nowoutworzony obiekt
*/
MapPoint inTheMiddle(MapPoint *city_1, MapPoint *city_2, std::string nazwa);

/** Funkcja sprawdza ktore z dwoch miast jest blizej punktu referencyjnego
@param punkt referencyjny
@param pierwsze miasto
@param drugie miasto
@return miasto ktore jest blizej punktu referencyjnego
*/
MapPoint closestFrom(MapPoint *reference_point, MapPoint *city_1, MapPoint *city_2);

/** Funkcja pobiera nazwe obiektu
@param miasto lub punkt
@return element name przekazanego obiektu
*/
std::string name(MapPoint target);

/** Funkcja dealokuje podane punkty
*/
void clear(MapPoint *point_1, MapPoint *point_2, MapPoint *point_3);
/** Funkcja dealokuje tylko jeden punkt
*/
void clear(MapPoint *point);