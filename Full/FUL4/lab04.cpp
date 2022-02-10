#include "lab04.h"
#include <iostream>

MapPoint* construct(std::string nazwa, double y, double x){
	MapPoint *a = (MapPoint*)malloc(sizeof(MapPoint));
	strcpy(a->name,nazwa.c_str());
	a->longitude = x;
	a->latitude = y;
	return a;
}

void print(MapPoint *city){
	std::cout << "Position of " << city->name << ". Latitude " << city->latitude << ".  Longitude " << city->longitude << std::endl;
}

MapDist distance(MapPoint *city_1, MapPoint city_2){
	MapDist a;
	a.latitude = city_1->latitude - city_2.latitude;
	a.longitude = city_1->longitude - city_2.longitude;
	return a;
}

double distanceMag(MapDist dane){
	return sqrt(dane.latitude*dane.latitude + dane.longitude*dane.longitude);
}

MapPoint inTheMiddle(MapPoint *city_1, MapPoint *city_2, std::string nazwa){
	MapPoint a;
	strcpy(a.name,nazwa.c_str());
	a.longitude = city_1->longitude - city_2->longitude;
	a.latitude = city_1->latitude - city_2->latitude;
	return a;
}

MapPoint closestFrom(MapPoint *reference_point, MapPoint *city_1, MapPoint *city_2){
	MapDist distance_1 = distance(reference_point, *city_1);
	MapDist distance_2 = distance(reference_point, *city_2);
	if(distanceMag(distance_1) <= distanceMag(distance_2))
		return *city_1;
	else
		return *city_2;
}

std::string name(MapPoint target){
	std::string nazwa = target.name;
	return nazwa;
}

void clear(MapPoint *point_1, MapPoint *point_2, MapPoint *point_3){
	free(point_1);
	point_1 = NULL;
	free(point_2);
	point_2 = NULL;
	free(point_3);
	point_3 = NULL;
}

void clear(MapPoint *point){
	free(point);
	point = NULL;
}