#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP
#include <iostream>
#include <exception>
#include <stdexcept>
#include "Types.h"
#include "Shape.h"
#include "Point.h"
#include "MyString.h"
#include "Rectangle.h"
#include "Constants.h"
///class Cricle derived from a base class shape
class Circle :public Shape
{
	///private properties
private:
///the center of the circle
	Point center;
	///colour of the circle
	MyString fill;
	///radius of the circle
	float radius;
	///function that sets the radius of the circle
	void setRadius(float _radius);
	///public properties
public:
///default constructor
	Circle() = default;
	///costructor with parameters
	Circle(Point _center,MyString _fill, float _radius);
	///function clone that return a new instance of the circle
	Circle* clone() const override;
	///destructor
	~Circle() override {};
	///return the radius of the circle
	float getRadius() const { return radius; }
	///returns the radius of the Circle
	Point getCenter() const { return center; }
	///return the fill Colour of the circle
	MyString getFillColour() const { return fill; }
	///printing the circle
	void print(std::ostream& = std::cout)const override;
	///printing the circle but with a new line
	void println(std::ostream& out = std::cout)const override;
	///translates the circle
	void translate(int, int) override;
	///checks if the circle is inside another circle
	bool withinCircle(Circle const& region)const  override;
	///checks if the circle is inside rectangle
	bool withinRectangle(Rectangle const& region)const override;
	///reads circle from a text file
	void readFromText(std::fstream& in);
	///writes circle to a text file
	void writeToText(std::fstream& out);
	///returns the type of the shape
	ShapeType getType() const override { return ShapeType::circle; }
	///return the type but with a string
	MyString getShape() const override { return "circle"; }
};
#endif // !_CIRCLE_HPP



