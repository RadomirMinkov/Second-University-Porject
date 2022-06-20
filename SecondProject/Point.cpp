#include "Point.h"

Point::Point(float _X, float _Y)
	:X(_X), Y(_Y) {}

void Point::print(std::ostream& out)const
{
	out << '(' << X << ',' << Y << ')';
}

bool Point::operator==(Point const& other)const
{
	return X == other.X && Y == other.Y;
}

bool Point::operator!=(Point const& other)const
{
	return !(*this == other);
}

void Point::setX(float _X)
{
	X = _X;
}
void Point::setY(float _Y)
{
	Y = _Y;
}
std::istream& operator>>(std::istream& in, Point& point)
{
	if (&std::cin == &in)
		std::cout << "X: ";
	in >> point.X;
	if (&std::cin == &in)
		std::cout << "Y: ";
	return in >> point.Y;
}

void Point::println(std::ostream& out)const
{
	print(out);
	out << '\n';
}
std::ostream& operator<<(std::ostream& out, Point const& point)
{
	point.println(out);
	return out;
} 