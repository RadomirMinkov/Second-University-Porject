#ifndef _CONTAINER_HPP
#define _CONTAINER_HPP


#include "Constants.h"
#include "Types.h"
#include "Shape.h"
#include "MyString.h"
#include "MyVector.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "LinkedStack.h"
///class Container which has the basics functions of the vector of Shapes
class Container
{
	///private properties
private:
///vector of pointers to shapes
	MyVector<Shape*> shapes;
	///number of the shapes in the vector
	size_t shapesNumber() const;
	///public properties
public:
///default constructor
	Container() = default;
	///constructor with parameters
	Container(MyVector<Shape*> _shapes);
	///adding shape to the vector
	void addShape(const Shape* newShape);
	///erasing shape to the vector
	void eraseShape(unsigned n);
	///printing the vector
	void print(std::ostream& out = std::cout) const noexcept;
	///translates shapes in the vector
	void translate(int vertical,int horizontal,int n=0)const noexcept;
	///checks how many shapes are inside a Circle
	void withinCircle(Circle const& region)const noexcept; 
	///checkshow many shapes are inside a Rectangle
	void withinRectangle(Rectangle const& region)const noexcept;
	///reads shapes from a text file
	void readFromText(std::fstream& in);
	///writes shapes to a text file
	void writeToText(std::fstream& out)const;
};


#endif // !_CONTAINER_HPP



