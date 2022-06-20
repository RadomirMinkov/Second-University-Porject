#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP
#include <cmath>
#include <fstream>
#include "Types.h"
#include "Shape.h"
#include "Point.h"
#include "MyString.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Constants.h"
/**
 * @brief class rectangle which is derived form base class shape
 * 
 */
class Rectangle :public Shape
{
	///private properties
private:
///point which points to the top left corner of the rectangle
	Point topLeft;
	///width of the rectangle
	float width;
	///height of the rectangle
	float height;
	///rounded by X-axis
	float roundX;
	///rounded by Y-axis
	float roundY;
	///colour of the border
	MyString colour;
	///colour inside the rectangle
	MyString fill;
	///function that sets the width
	void setWidth(float);
	///fucntion that sets the height
	void setHeight(float);
	///fucntion that sets the rounding by X-axis
	void setRoundX(float);
	///function that sets the rounding by Y-axis
	void setRoundY(float);
	///top right corner of the rectangle
	Point topRight;
	///bottom left corner of the rectangle
	Point bottomLeft;
	///bottom right corner of the rectangle
	Point bottomRight;
	///public proeprties
public:
///default constructor
	Rectangle() = default;
	///constructor with parameters
	Rectangle(Point _topLeft,MyString _colour,MyString _fill,
		 float _width = 0, float _height = 0,float _roundX = 0, float _roundY = 0);
		 ///destructor 
	~Rectangle() override {};
	///function that returns a new copy of the rectangle
	Rectangle * clone() const override;
	///return the width
	float getWidth() const { return width; }
	///return the height
	float getHeight() const { return height; }
	///returns the rounding by X-axis
	float getRoundX() const { return roundX; }
	///returns the rounding by Y-axis
	float getRoundY() const { return roundY; }
	///return the border colour
	MyString getColour() const { return colour; }
	///returns the inside colour
	 MyString getFillColour() const { return fill; }
	 ///return the top left corner
	 Point getTopLeftCorner() const { return topLeft; }
	 //return the top right corner
	 Point getTopRightCorner() const { return topRight; }
	 ///return the bottom left corner
	 Point getBottomLefttCorner() const { return bottomLeft; }
	 ///return the bottom right corner
	 Point getBottomRightCorner() const { return bottomRight; }
	 ///printing the rectangle
	void print(std::ostream& = std::cout)const override;
	///printing the shape but with a new line
	void println(std::ostream& out = std::cout)const override;
	///translates the rectangle
	void translate(int vertical, int horizontal) override;
	///checks if the rectangle is inside another rectangle
	bool withinRectangle( Rectangle const& region)const  override;
	///checks if the rectangle is inside a circle
	bool withinCircle(Circle const& region)const  override;
	///reads rectangle from a text file
	void readFromText(std::fstream& in);
	///writes rectangle to a text file
	void writeToText(std::fstream& out);
	///returns the type of the rectangle
	ShapeType getType() const override { return ShapeType::rectangle; }
	///return the type but with a string
	MyString getShape() const override { return "rectangle"; }
};
#endif // !_RECTANGLE_HPP



