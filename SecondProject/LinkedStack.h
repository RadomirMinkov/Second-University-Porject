#ifndef _LINKEDSTACK_HPP
#define _LINKEDSTACK_HPP
#include <stdexcept>
#include <exception>
#include <iostream>
#include "MyString.h"
#include "MyVector.h"
///Struct that represents the element of the stack
struct StackElement
{
	///type of the element
	MyString data;
	///pointer to the next element of the stack
	StackElement* next;
};
///class LinkedStack which helps for the reaidng of the files
class LinkedStack
{
	///private properties
private:
///pointer to the element of the stack that is on the top
	StackElement* top;
	///function that copies the stack
	void copy(LinkedStack const& other);
	///fucntion that frees all the memory by the stack
	void clear();
	///public properties
public:
///default constructor
	LinkedStack();
	///copy constructor 
	LinkedStack(LinkedStack const& other);
	///copy assignment
	LinkedStack& operator=(LinkedStack const& other);
	///destructor of the stack
	~LinkedStack();
	///checks if the stack is empty
	bool isEmpty()const noexcept;
	///adding new element to the top of the stack
	void push(MyString const& element);
	///shows the element on the top of the stack
	bool peek(MyString& element)const ;
	///removes the element on the top of the stack
	MyString pop();

};
#endif // !_LINKEDSTACK_HPP


