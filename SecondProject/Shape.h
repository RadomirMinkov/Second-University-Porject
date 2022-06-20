#ifndef _SHAPE_HPP
#define _SHAPE_HPP
#include <iostream>
#include <cmath>
#include "Types.h"
#include "Point.h"
#include "MyString.h"
/**
 * @brief enum class which defines the differnet types of shapes
 * 
 */
enum class ShapeType
{
	rectangle=1,
	circle=2,
	line=3
};	
///base abstract class Shape
class Shape
{
	///private properties
private:
///protected properties
protected:
/**
 * @brief gets you the distance between two points
 * 
 * @return double return the distnace as double
 */
	double getDistance(Point, Point)const;
public:
///virtual destructor
	virtual ~Shape() {};
	///virtual fucntion clone that makes a copy
	virtual Shape* clone() const = 0;
/// virtual fucntion for printing the object
	virtual void  print(std::ostream& = std::cout)const=0;
	///print but witha new line
	virtual void println(std::ostream& = std::cout)const=0;
	///virtual function that translates the shape
	virtual void translate(int,int)=0;
	/**
	 * @brief checks if a shape is inside rectangle
	 * 
	 * @param region the region in which the shape should be
	 * @return true is within
	 * @return false is not within
	 */
	virtual bool withinRectangle(Rectangle const& region)const=0;
	/**
	 * @brief checks if a shape is inside a circle
	 * 
	 * @param region the region in which the shape should be
	 * @return true is within
	 * @return false is not within
	 */
	virtual bool withinCircle(Circle const& region)const = 0;
	///gets you the type of the shape
	virtual ShapeType getType() const = 0;
	///gets you the type in a string
	virtual MyString getShape() const = 0;
	///reads a shape form a text file
	virtual void readFromText(std::fstream& in)=0;
	///writes a shape to a text file
	virtual void writeToText(std::fstream& out) = 0;
};
#endif // !_SHAPE_HPP


