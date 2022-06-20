#include "Circle.h"

Circle* Circle::clone() const
{
	return new Circle(*this);
}

void Circle::setRadius(float _radius)
{
	if (_radius >=0)
	{
		radius = _radius;
	}
	else
	{
		throw std::exception("Parsing error!\n");
		//to catch exception
	}
}

Circle::Circle(Point _center, MyString _fill,float _radius)
	:center(_center),fill(_fill)
{
		setRadius(_radius);
}
void Circle::print(std::ostream& out)const
{
	out <<"Circle with center (" << center.getX() << ',' << center.getY() << ") and radius of " << radius << '.';
}
void Circle::println(std::ostream& out)const
{
	print(out);
	out << '\n';
}

void Circle::translate(int horizontal, int vertical)
{
	center.setX(horizontal + center.getX());
	center.setY(vertical + center.getY());
}

bool Circle::withinCircle(Circle const& region)const
{
	double distanceBetweenCenters = getDistance(center, region.center);
	if (distanceBetweenCenters + radius <= region.radius)
	{
		return true;
	}
		return false;

}

bool Circle::withinRectangle(Rectangle const& region)const
{
	if (std::abs(region.getTopLeftCorner().getX()-center.getX())>=radius && 
		std::abs(region.getTopLeftCorner().getY()-center.getY())>=radius &&
		std::abs(region.getBottomRightCorner().getX()-center.getX())>=radius &&
		std::abs(region.getBottomRightCorner().getY()-center.getY())>radius)
		return true;
	return false;
}

void Circle::readFromText(std::fstream& in)
{
	float x;
	float y;
	char arr[BUFFER_LENGHT];
	in.getline(arr, BUFFER_LENGHT);
	char* pointerToQuote = strstr(arr, "\"") + 1;
	in >> x;
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	in >> y;
	center.setX(x);
	center.setY(y);
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	in >> fill;
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	in >> radius;
}

void Circle::writeToText(std::fstream& out)
{
	out << '<';
	out << getShape() << " cx=\"" << center.getX() << "\" cy=\"" << center.getY() << "\" radius=\"" << radius << "\"  fill=\"" << fill << "\" />\n";
}