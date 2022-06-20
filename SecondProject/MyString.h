#ifndef _MYSTRING_HPP
#define _MYSTRING_HPP
#include <iostream>
#include <cstring>
#include <exception>
///class String which takes care of the used memory 
class MyString
{
	///private properties
private:
///the array ot used data
	char* data{ nullptr };
	///size of the array
	size_t size;
	///public properties
public:
/// constructor with default parameters
	MyString(const char* _data = "unkwown");
	///copy constructor
	MyString(MyString const& other);
	///copy assignment
	MyString& operator=(MyString const& other);
	//destructor
	~MyString();
	///return the array
	const char* getString() const { return data; }
	///return the size
	size_t getSize() const { return size; }
	//copies the string from the string in the parameters
	void copy(MyString const& other);
	//void copyNSymbols(MyString const& other);
	///copies the first n symbols from a string
	void copyNSymbols(const char* other, int&  n);
	///deletes the string
	void deleteString();
	///prints the array
	void printString(std::ostream& out = std::cout)const;
	///prints the string
	void print(std::ostream& out=std::cout) const;
	///prints the string with a new line
	void println(std::ostream& out)const;
	///operator for incerting information
	friend std::istream& operator>>(std::istream& in, MyString& other);
	///function that checks if two strings are equal
	bool operator==(MyString const& other)const;
	///function that checks if two strings are different
	bool operator!=(MyString const& other)const;
};
///function that prints the string on the console
std::ostream& operator<<(std::ostream& out, MyString const& other);
#endif // !_MYSTRING_HPP



