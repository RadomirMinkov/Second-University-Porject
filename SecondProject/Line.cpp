#include "Line.h"

Line * Line::clone() const
{
	return new Line(*this);
}
Line::Line(Point _begin, Point _end,MyString _stroke, unsigned _strokeWidth)
	:begin(_begin),end(_end),stroke(_stroke),strokeWidth(_strokeWidth){}

double Line::length()const
{
	return getDistance(begin,end);
}

void Line::print(std::ostream& out)const
{
	out << "Line with length " << length() << " point A";
	begin.print(out);
	out << " for a begining and B";
	end.print(out);
	out << "for an end with ";
	stroke.printString();
	out << " and its width is " << strokeWidth;
}

void Line::println(std::ostream& out)const
{
	print(out);
	std::cout << '\n';
}

void Line::translate(int vertical, int horizontal)
{
	begin.setX(begin.getX() + horizontal);
	begin.setY(begin.getY() + vertical);
	end.setX(end.getX() + horizontal);
	end.setY(end.getY() + vertical);
}

bool Line::withinCircle(Circle const& region)const
{
	double distanceToBegining = getDistance(begin, region.getCenter());
	double distanceToEnd = getDistance(end, region.getCenter());
	if (distanceToBegining <= region.getRadius() && distanceToEnd <= region.getRadius())
		return true;
	return false;
}
bool Line::withinRectangle(Rectangle const& region)const
{
	if (begin.getX() >= region.getTopLeftCorner().getX() && begin.getX() <= region.getTopRightCorner().getX() &&
		begin.getY() >= region.getTopLeftCorner().getY() && begin.getY() <= region.getBottomRightCorner().getY() &&
		end.getX() >= region.getTopLeftCorner().getX() && end.getX() <= region.getTopRightCorner().getX() &&
		end.getY() >= region.getTopLeftCorner().getY() && end.getY() <= region.getBottomRightCorner().getY())
		return true;
	return false;
}
void Line::readFromText(std::fstream& in)
{
	try
	{
		char arr[BUFFER_LENGHT];
		in.getline(arr, BUFFER_LENGHT);
		char* pointerToQuote = strstr(arr, "\"") + 1;
		float x;
		float y;
		in >> x;
		pointerToQuote = strstr(pointerToQuote, "\"") + 1;
		in >> y;
		begin.setX(x);
		begin.setY(y);
		pointerToQuote = strstr(pointerToQuote, "\"") + 1;
		in >> x;
		pointerToQuote = strstr(pointerToQuote, "\"") + 1;
		in >> y;
		begin.setX(x);
		begin.setY(y);
		pointerToQuote = strstr(pointerToQuote, "\"") + 1;
		in >> stroke;
		pointerToQuote = strstr(pointerToQuote, "\"") + 1;
		in >> strokeWidth;
	}
	catch (const std::exception& e)
	{
		std::cout << "Invalid data!";
	}
}

void Line::writeToText(std::fstream& out)
{
	out << '<';
	out << getShape() << " x1=\"" << begin.getX() << "\" y1=\"" << begin.getY() << "\" x2=\"" << end.getX()
		<< "\" y2=\"" << end.getY() << "\" stroke=\"" << stroke << "\" stroke-width\"" << strokeWidth << "\" />\n";
}