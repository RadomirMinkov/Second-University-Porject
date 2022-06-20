#include "Shape.h"

double Shape::getDistance(Point _begin, Point _end) const
{
	return std::sqrt(std::pow(_begin.getX() - _end.getX(),2) + std::pow(_begin.getY() - _end.getY(),2));
}