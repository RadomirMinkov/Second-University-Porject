#ifndef _POINT_HPP
#define _POINT_HPP
#include <iostream>
///class Point 
class Point
{
	//private properties
private:
///coordinates by X-axis
	float X;
	///coordinates by Y-axis
	float Y;
	//public properties
public:
///constructor with default parameters
	Point(float X = 0, float Y = 0);
	///prints the point
	void print(std::ostream& out=std::cout) const;
	///prints the point with a new line
	void println(std::ostream& out = std::cout)const;
	///sets the X of the point
	void setX(float _X);
	///sets the Y of the point
	void setY(float _Y);
	///checks if two points are equal 
	bool operator==(Point const& other)const;
	///checks if two points are different
	bool operator!=(Point const& other)const;
	///return the Y of the Point
	float getY() const { return Y;}
	///return the X of the Point
	float getX() const { return X; }
	///operator for incerting the point
	friend std::istream& operator>>(std::istream& in,Point& other);
};
///operator for printing the point on the console
std::ostream& operator<<(std::ostream& out, Point const& other);
#endif // !_POINT_HPP



