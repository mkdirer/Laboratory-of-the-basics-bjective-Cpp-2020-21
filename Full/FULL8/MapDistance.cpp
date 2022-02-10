#include <iostream>
#include "MapDistance.h"

double abs(const double& data)
{
  if(data < 0) return -data;
  else return data;
}

void MapDistance::set_coordinates(const double& latid, const double& longid)
{
  latidiff=latid;
  longidiff=longid;
}

void MapDistance::print()
{
    std::cout <<"Point: (" << latidiff <<", "<<longidiff<<"}"<<std::endl;

}