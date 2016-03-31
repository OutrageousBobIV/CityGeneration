#pragma once
#include "BuildingRegion.h"
#include "Point.h"
#include <list>

class BuildingRegion;

///Defines a region for a building lot - comprised of a set of points.
///Owned by a building region
class BuildingLot {
protected:
	std::list<Point> points;
	BuildingRegion* owner;
public:
	std::list<Point> getPoints();
	BuildingLot();
	~BuildingLot();
};
