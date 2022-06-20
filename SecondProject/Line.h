#ifndef _LINE_HPP
#define _LINE_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include "Types.h"
#include "Shape.h"
#include "Point.h"
#include "MyString.h"
#include "Rectangle.h"
#include "Constants.h"
/**
 * @brief class line which is derived from the base class shape
 * 
 */
class Line:public Shape
{
	///private properties
private:
/**
 * @brief point to the begining of the  line
 * 
 */
	Point begin;
	///point to the end of the line
	Point end;
	///the stroke of the line
	MyString stroke;
	///width of the stroke
	unsigned strokeWidth{1};
	///public properties
public:
///default constructor
	Line() = default;
	///constructor with parameters
	Line(Point _begin,Point _end,MyString _stroke,unsigned _strokeWidth);
	///destructor
	~Line() override {}
	///function that returns a new instance of the line
	Line* clone()const override;
	///return the length of the line
	double length() const;
	///return the begining point
	Point getBegin() const { return begin; }
	//return the ending point
	Point getEnd() const { return end; }
	///returns the stroke of the line
	MyString getStroke() const { return stroke; }
	/**
	 * @brief printing the line with its properties
	 * 
	 */
	void  print(std::ostream& = std::cout)const override;
	///printing the properties of the line with a new line
	 void println(std::ostream& = std::cout)const override;
	 ///translates the line 
	 void translate(int, int) override;
	 ///checks if the line is within a rectangle
	 bool withinRectangle(Rectangle const& region)const override;
	 ///checks if the line is within a circle
	 bool withinCircle(Circle const& region)const override;
	 ///function that reads a line form a file
	 void readFromText(std::fstream& in);
	 ///function writing to a text file
	 void writeToText(std::fstream& out);
	 ///returns the type of the shape
	 ShapeType getType() const override { return ShapeType::line; }
	 ///return the type but with a string
	 MyString getShape() const override { return "line"; }
};
#endif


