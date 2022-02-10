#include <iostream>
#include "MapDistance.h"
#include "MapPoint.h"

void MapPoint::set_coordinates(const double& latit, const double& longit)
{
  latitude = latit;
  longitude = longit;
}

void MapPoint::print()
{
  std::cout <<"Point: (" << latitude <<", "<<longitude<<"}"<<std::endl;
}

MapDistance MapPoint::distance(const MapPoint& point)
{
  MapDistance resoult;
  resoult.set_coordinates(abs(point.latitude - latitude), abs(point.longitude - longitude));
  return resoult;
}

MapPoint MapPoint::half_way_to(const MapPoint point)
{
  MapPoint resoult;
  resoult.set_coordinates((latitude + point.latitude)/2, (longitude+ point.longitude)/2);
  return resoult;
}