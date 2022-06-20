#include "LinkedStack.h"

void LinkedStack::clear()
{
	while (!isEmpty())
		pop();
}

void LinkedStack::copy(LinkedStack const& other)
{
	if (other.top == nullptr)
		return;
	top = new StackElement{ other.top->data,nullptr };
	StackElement* last = top;
	StackElement* elementToCopy = other.top->next;
	while (elementToCopy)
	{
		last->next = new StackElement{ elementToCopy->data,nullptr };
		last = last->next;
		elementToCopy = elementToCopy->next;
	}
}
LinkedStack::LinkedStack() :top(nullptr) {}

LinkedStack::LinkedStack(LinkedStack const& other)
	:top(nullptr)
{
	copy(other);
}

LinkedStack& LinkedStack::operator=(LinkedStack const& other)
{
	LinkedStack copy{ other };
	std::swap(*this, copy);
	return *this;
}
LinkedStack::~LinkedStack()
{
	clear();
}

bool LinkedStack::isEmpty()const noexcept
{
	return top == nullptr;
}
void LinkedStack::push(MyString const& element)
{
	StackElement* newEl{};
	newEl->data = element;
	newEl->next = top;
	top = newEl;
}

bool LinkedStack::peek(MyString& element) const
{
	if (isEmpty())
		throw std::out_of_range("The stack is empty");
	element = top->data;
	return true;
}

MyString LinkedStack::pop()
{
	if (isEmpty())
		throw std::out_of_range("The stack is empty");
	StackElement* newtop = top->next;
	MyString temp = top->data;
	delete top;
	top = newtop;
	return temp;
}