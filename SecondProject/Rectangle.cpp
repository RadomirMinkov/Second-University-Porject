#include "Rectangle.h"

void Rectangle::setWidth(float _width)
{
	if (_width>=0)
	{
		width = _width;
	}
	else
	{
		width = 0;
	}
}
void Rectangle::setHeight(float _height)
{
	if (_height >= 0)
	{
		height = _height;
	}
	else
	{
		height = 0;
	}
}
void Rectangle::setRoundX(float _roundX)
{
	if (_roundX>=0)
	{
		roundX = _roundX;
	}
	else
	{
		roundX = 0;
	}
}
void Rectangle::setRoundY(float _roundY)
{
	if (_roundY>=0)
	{
		roundY = _roundY;
	}
	else
	{
		roundY = 0;
	}
}

Rectangle* Rectangle::clone() const
{
	return new Rectangle(*this);
}

Rectangle::Rectangle(Point _topLeft,MyString _fill, MyString _colour,
	float _width, float _height,float _roundX, float _roundY)
	:topLeft(_topLeft), colour(_colour),fill(_fill)
{
	setWidth(_width);
	setHeight(_height);
	setRoundX(_roundX);
	setRoundY(roundY);
}

void Rectangle::print(std::ostream& out)const
{
	out << "Rectangle with top left corner ";
	topLeft.print(out);
	out << ".\n It has " << width << " width and " << height << " height.\n It is painted in ";
	colour.printString(out);
	out << '.';
	if (roundX>0 && roundY>0)
	{
		out << "The shape is rounded by RX:" << roundX << "and RY:" << roundY;
	}
}

void Rectangle::println(std::ostream& out)const
{
	print(out);
	out << '\n';
}

void Rectangle::translate(int vertical, int horizontal)
{
	 topLeft.setX( horizontal+topLeft.getX());
	 topLeft.setY(vertical + topLeft.getY());
	//roundY += vertical;
}
void Rectangle::readFromText(std::fstream& in)
{
	/*Point topLeft;
	float width;
	float height;
	float roundX;
	float roundY;
	MyString colour;
	MyString fill;*/
	float x;
	float y;
	char arr[BUFFER_LENGHT];
	in.getline(arr, BUFFER_LENGHT);
	char* pointerToQuote = strstr(arr, "\"") + 1;
	in >> x;
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	in >> y;
	topLeft.setX(x);
	topLeft.setY(y);
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	in >> width;
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	in >> height;
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	in >> colour;
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	in >> fill;
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	if (pointerToQuote != nullptr)
		in >> roundX;
	pointerToQuote = strstr(pointerToQuote, "\"") + 1;
	if (pointerToQuote!=nullptr)
	in >> roundY;
}
void Rectangle::writeToText(std::fstream& out)
{
	out << '<';
	out << getShape() << "x=\"" << topLeft.getX() << "\" y=\"" << topLeft.getY() << "\" width=\"" << width << "\" height=\"" << height
		<< "\" colour=\"" << colour << "\" fill=\"" << fill << "\"";
	if (roundX != 0)
		out << " rx=\"" << roundX << "\"";
	if (roundY != 0)
		out << " ry=\"" << roundY << "\" />\n";
}
bool Rectangle::withinRectangle( Rectangle const& region)const
{
	if (topLeft.getX()>=region.topLeft.getX() && topLeft.getY()>=region.topLeft.getY()
		&&topLeft.getX()+width<=region.topLeft.getX()+region.width && topLeft.getY()+height <=region.topLeft.getY()+region.height)
		return true;
	return false;
}

bool Rectangle::withinCircle(Circle const& region)const
{
	if (std::abs(topLeft.getX() - region.getCenter().getX()) <= region.getRadius() &&
		std::abs(topLeft.getY() - region.getCenter().getY()) <= region.getRadius() &&
		std::abs(bottomRight.getX() - region.getCenter().getX()) <= region.getRadius() &&
		std::abs(bottomRight.getY() - region.getCenter().getY()) <= region.getRadius())
		return true;
	return false;
}